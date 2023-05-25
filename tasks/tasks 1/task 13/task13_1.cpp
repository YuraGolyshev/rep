#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cout << "BBedite stroky" << "\n";
    getline(cin, str); // Ввод строки
    int m = 0;
 
    for (int i = 0; i < str.length(); i++)  // Цикл
        if (isdigit(str[i]))                // Проверка является ли i-ый элемент числом 
            if (((str[i] - '0') % 2 == 0) && ((str[i] - '0') > m)) // Проверка четности и больше ли m   
                m = str[i] - '0';                                  // Новый максимальный элемент
          
    cout << m << "\n"; // Вывод максимального четного числа
    system("pause");
    return 0;
}
