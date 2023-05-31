#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cout << "BBedite stroky" << "\n";
    getline(cin, str); // Ввод строки
    char x;
    cout << "BBedite bykvy" << "\n";
    cin >> x;          // Ввод буквы
    
    for (int i = 0; i < str.length(); i++)  // Цикл
        if(str[i] == x && (str[i-1] == ' ' || i == 0)) // Ищем начало слова с x
            {
            while((str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '"' && str[i] != ':' && str[i] != ';' && str[i] != '-' && str[i] != '?' && str[i] != '!') && i < str.length())  // ищем конец слова
                i++;
            str.insert(i, 1, ':');          // Вставляем :
            }
    cout << str << "\n"; // Вывод строки
    system("pause");
    return 0;
}
