#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cout << "BBedite predl" << "\n";
    getline(cin, str);  // Ввод строки
    string alphabet = "abcdefghijklmnopqrstuvwxyz";     // Алфавит
    int* a = new int[26]{ 0 };  // создание массива для подсчета букв
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < str.size(); j++) 
        {
            bool bykva = false;
            while((str[j] != ' ' && str[j] != ',' && str[j] != '.' && str[j] != '"' && str[j] != ':' && str[j] != ';' && str[j] != '-' && str[j] != '?' && str[j] != '!') && j < str.size())  // ищем конец слова
            {
                if(str[j] == alphabet[i])
                    bykva = true;
                j++;
            } 
            if(bykva)
                a[i]++;
        }
    }
    int m, max = 0;
    for(int i = 0; i < 26; i++)
    {
        if(a[i] > max)
        {
            max = a[i];  // максимальное количество
            m = i;
        }
    }
    cout << alphabet[m] << " B " << max << " slovax" << "\n"; // вывод буквы, которая встречается в максимальном количестве слов
    system("pause");
    return 0;
}
