#include <locale.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // ����� ������� �����
    system("chcp 1251"); // ����������� ��������� �������

    vector <string> slova;   
    ifstream file("C:\\Users\\79370\\Desktop\\fortask\\SLOVA.txt"); // ��������� ���� �� ������� 
    string sl;
    while(getline(file, sl))    // ��������� � ����� ����� � �������
        slova.push_back(sl);

    set <char> bukv;
    vector <string> alf = {"�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�"}; // ������ � ���������
    string slovo, out, in, buff;
    int p = 10; int v = 4;  // p ���-�� ������� v - �������� ����������, ��� ���� � ������� ���� �����
    
    srand((unsigned int)time(0));   
    int r = rand() % (slova.size()-1);  // �������� ��������� ����� �� ������� �� �������
    slovo = slova[r];
 
    for(int i=0; i<slovo.length();i++) // ������� ������ ��� ������ 
        out += "_";

    for(int i=0; i<p; i++) // ���� ���� ���� �� �������� �������
    {
        for(auto it : alf)
            cout << it << " ";  // ����� ��������
        cout << "\n";
        
        if(v == 3)  // ���-���
        {
            cout << "����... " << slovo << "\n";
            i--;    // �� ������� �������
        }

        if(v == 2)  // ����� ����� ��� �������
        {
            cout << "�� ��-����� ���������" << "\n" << "����� ����� ��� ����" << "\n";
            i--;    // �� ������� �������
        }
        
        if(v == 1)  // �����, ����� ������� ����� 
        {
            cout << "�� �������!" << "\n";
            i--;    // �� ������� ������� 
        }
        
        if(v == 0)  // �����, ����� �� ������� �����
            cout << "�� �� �������(" << "\n";
        v = 0;

        cout << "� ��� �������� " << p-i << " �������(-��,-��)" << "\n"; // ����� ���-�� �������
        cout << "�����: " << out << "\n";   // ����� ����� � ��� ������� ���������
        cout << "������� ����� ��� �� �����:"; cin >> in;  // ���� ����� ��� �����
        cout << "\n";

        for(auto it = alf.begin(); it != alf.end(); it++) // "�����������" �����, ������� �����
            if(it == find(alf.begin(), alf.end(), in))
                *it = "/" + in + "/";

        if(in.length() == 1) //���� ����� �����
        {
            if(bukv.find(in[0]) == bukv.end())  // ���� �� ����� �� ������� ����� �����
            {
                for(int b=0; b < slovo.length();b++)    // ���� �������� ����, ���� �������
                {
                    if(in[0] == slovo[b])
                    {
                        out[b] = slovo[b];
                        v = 1;
                    }
                }
            }
            else // ���� ����� ����� ��� ����
                v = 2;
            bukv.insert(in[0]); // ���������� �����, ������� �����
        }
        
        else // ���� ����� ����� ��� �����
        {
            if(in == slovo) // ��������� ��������� ��
            {
                out = slovo;    // ��������� ��� ����� � ����������� ����
                break;
            }
            else    
                v = 0;
        }
        if(in == "���-���") // ���-���
            v = 3;
        system( "cls" );    // ������� �����
        if(out == slovo)    //  ���� ��� ����� ��������� �������� ��������� ����
            break;
    }

    int pr=0;
    for(int i=0; i<out.length(); i++)   // ���������, ���� �� � ������ "_"
    {
        if(out[i] == '_')   // ���� ���� - ���������
            pr++;
    }

    if(pr == 0)
        cout << "�� ��������!" << "\n"; // ��������� � ������ 
    else
        cout << "�� ���������(" << "\n";// ��������� � ���������
    cout << "��� ���� �����: " << slovo;// ����� �����
    cout << "\n";
    system("pause");
    return 0;
}