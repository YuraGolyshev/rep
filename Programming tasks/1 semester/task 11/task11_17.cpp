#include <iostream>
#include <cmath>
 
using namespace std;

void print_char(int n, char d) // Печатает n символов d
{
    for(int i = 0; i < n; i++)
        cout << d;
}

void print(int n, int a) // Печатает n цифр
{
    for(int i = 0; i < n; i++)
        cout << a;
}

void F(int d, int n, int a, int k) // рекурсивная функция для печати таблицы
{
    if (n < k) 
    {
        print(n, a); // Печать цифр
        print_char(d, '-'); // Печать дефисов
        print(n, a); // Печать цифр
        cout << '\n'; // Переход на след. строку
        F(d-2, n+1, a+1, k); // Вызов функции для след. строки
        print(n, a);        // Нижняя часть
        print_char(d, '-'); 
        print(n, a);
        cout << '\n'; 
    }  
}

int main()
{
int N, k;
cout << "N = "; cin >> N;
k = N+1;
F(2 * (N-1), 1, 1, k); // Вызов функции
system("pause");
return 0;
}