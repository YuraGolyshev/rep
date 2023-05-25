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
    setlocale(LC_ALL, "Russian"); // задаЄм русский текст
    system("chcp 1251"); // настраиваем кодировку консоли

    vector <string> slova;   
    ifstream file("C:\\Users\\79370\\Desktop\\fortask\\SLOVA.txt"); // открываем файл со словами 
    string sl;
    while(getline(file, sl))    // считываем с файла слова в векстор
        slova.push_back(sl);

    set <char> bukv;
    vector <string> alf = {"а", "б", "в", "г", "д", "е", "Є", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "€"}; // вектор с алфавитом
    string slovo, out, in, buff;
    int p = 10; int v = 4;  // p кол-во попыток v - помогает определить, что было в прошлом шаге цикла
    
    srand((unsigned int)time(0));   
    int r = rand() % (slova.size()-1);  // выибраем случаеное слово из вектора со словами
    slovo = slova[r];
 
    for(int i=0; i<slovo.length();i++) // создаем строку дл€ вывода 
        out += "_";

    for(int i=0; i<p; i++) // цикл идет пока не кончатс€ попытки
    {
        for(auto it : alf)
            cout << it << " ";  // вывод алфавита
        cout << "\n";
        
        if(v == 3)  // чит-код
        {
            cout << "эххх... " << slovo << "\n";
            i--;    // не снимаем попытку
        }

        if(v == 2)  // когда букву уже вводили
        {
            cout << "“ы по-моему перепутал" << "\n" << "“ака€ буква уже была" << "\n";
            i--;    // не снимаем попытку
        }
        
        if(v == 1)  // вывод, когда угадали букву 
        {
            cout << "¬ы угадали!" << "\n";
            i--;    // не снимаем попытку 
        }
        
        if(v == 0)  // вывод, когда не угадали букву
            cout << "¬ы не угадали(" << "\n";
        v = 0;

        cout << "” вас осталось " << p-i << " попыток(-ки,-ка)" << "\n"; // вывод кол-ва попыток
        cout << "—лово: " << out << "\n";   // вывод слова в его текущем состо€нии
        cout << "¬ведите букву или всЄ слово:"; cin >> in;  // ввод буквы или слова
        cout << "\n";

        for(auto it = alf.begin(); it != alf.end(); it++) // "зачеркиваем" буквы, котоыре ввели
            if(it == find(alf.begin(), alf.end(), in))
                *it = "/" + in + "/";

        if(in.length() == 1) //если ввели букву
        {
            if(bukv.find(in[0]) == bukv.end())  // если до этого не вводили такую букву
            {
                for(int b=0; b < slovo.length();b++)    // цикл открыти€ букв, если угадали
                {
                    if(in[0] == slovo[b])
                    {
                        out[b] = slovo[b];
                        v = 1;
                    }
                }
            }
            else // если така€ буква уже была
                v = 2;
            bukv.insert(in[0]); // запоминаем буквы, которые ввели
        }
        
        else // если ввели сразу все слово
        {
            if(in == slovo) // провер€ем правильно ли
            {
                out = slovo;    // открываем все буквы и заканчиваем цикл
                break;
            }
            else    
                v = 0;
        }
        if(in == "чит-код") // чит-код
            v = 3;
        system( "cls" );    // очищаем вывод
        if(out == slovo)    //  если зли слово открылось полность завершаем цикл
            break;
    }

    int pr=0;
    for(int i=0; i<out.length(); i++)   // провер€ем, есть ли в выводе "_"
    {
        if(out[i] == '_')   // если есть - проиграли
            pr++;
    }

    if(pr == 0)
        cout << "¬ы победили!" << "\n"; // сообщение о победе 
    else
        cout << "¬ы проиграли(" << "\n";// сообщение о поражении
    cout << "¬от ваше слово: " << slovo;// вывод слова
    cout << "\n";
    system("pause");
    return 0;
}