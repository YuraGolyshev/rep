#include <iostream>
#include <cmath>

using namespace std;

int main()
{
float a, b, h, x;
cout << "a = ";
cin >> a;   // ввод левой границы
cout << "b = ";
cin >> b;   // ввод правой границы
cout << "h = ";
cin >> h;   // ввод шага
x = a;
while (x <= b) // цикл пока x иеньше или равно b
{
    cout << "x = " << x << "\n";
    if(x*x - 4 * x + 4 == 0) // проверка деления на 0
    {
        cout << "delenie na nolb\n";
        x = x + h;
    }
    else if(x*x - 1 <= 0)   // проверка логарифма из неположительного числа
    {
        cout << "logarifm iz nepolozhitelnogo chisla\n";
        x = x + h;
    }
    else if(x*x - 4 * x + 4 < 0) // проверка корная из отрицательного числа
    {
        cout << "kornb iz otritsatelnogo chisla\n";
        x = x + h;
    }
    else
    {
        float y = log(x*x - 1) / sqrt(x*x - 4 * x + 4); // функция
        cout << y << "\n";  // вывод значения функции
        x = x + h;
    }
}
system ("pause");
return 0;
}