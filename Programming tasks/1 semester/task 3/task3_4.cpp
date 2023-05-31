#include <cmath> 
#include<iostream> 

using namespace std; 

int main()
{ 
int a, y, x, n; // ввод данных
cout << "a = ";
cin >> a;
cout << "x = ";
cin >> x;
cout << "y = ";
cin >> y;
if (a >= 1000 || a < 100 || y >= 10 || y < 0 || x < 0 || x > 4) // проверка корректности ввода
{
    cout << "invalid input" << "\n";
}
else
{
int first = a / 100; 
int second = (a % 100) / 10; // разделение переменной a на отдельные числа
int third = a % 10; 

if (first % x == 0 && second % x == 0 && third % x == 0 ) // проверка кратности 
{
    first = (first * y) % 10;    
    second = (second * y) % 10;            // выполнение условий 
    third = (third * y) % 10;
}
else if (first % x == 0 && second % x == 0) // проверка кратности 
{
    first = (first * 3) % 10;    
    second = (second * 3) % 10;           // выполнение условий
    third = (third * 3) % 10;
}
else if (first % x == 0 && third % x == 0) // проверка кратности 
{
    first = (first + y) % 10;    
    second = (second + y) % 10;           // выполнение условий
    third = (third + y) % 10;    
}
else if (second % x == 0 && third % x == 0) // проверка кратности 
{
    first = abs(first - y) % 10;    
    second = abs(second - y) % 10;           // выполнение условий
    third = abs(third - y) % 10;             
}
else 
{
    first = (first * 2) % 10;    
    second = (second * 2) % 10;            // выполнение условий
    third = (third * 2) % 10;     
}
n = first * 100 + second * 10 + third; // построение нового числа 
cout << n << "\n"; // вывод новго числа
}
system("pause"); 
return 0;
}

