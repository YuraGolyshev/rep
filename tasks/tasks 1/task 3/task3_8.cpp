#include <cmath> 
#include<iostream>  

using namespace std; 

int main()
{   
float x;
cout << "x = "; // ввод x
cin >> x;
if (x > 4) cout << "koren iz otricatelnogo chisla" << endl; // проверка корня из отрицательного числа
else if ((x*x*x - 64) == 0) cout << "delenie na nolb" << endl; // проверка деления на ноль
else if ((x*x - 9) <= 0) cout << "logarifm otricatelnogo chisla" << endl; // проверка логарифма из отрицательного числа
else
{
    float f = sqrt(4 - x) / (x*x*x - 64) + log(x*x - 9); // функция
    cout << f << '\n'; // результат
}
system("pause"); 
return 0;
}