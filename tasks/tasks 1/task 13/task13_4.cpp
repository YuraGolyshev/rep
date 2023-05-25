#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string str;
    ifstream file("C:\\Users\\79370\\Desktop\\task\\file.txt");
    getline(file, str);
    int a = 0;
    int b, k = 0;
    int i = 0;
    cout << str << str.length();
    while(i < str.length())
    {
        while(k = 0)
        {
            if(str[i] == '.')
                if(str[i+1] == ' ')
                    k++;
            i++;
            b = i;
        }
        for(int j = a; j < b; j++)
            cout << str[j];
        a = b;    
        k = 0;
        cout << b;

    }
    system("pause");
    return 0;
}
