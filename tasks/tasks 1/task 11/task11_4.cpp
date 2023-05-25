#include <iostream>
#include <cmath>
 
using namespace std;

int fibo(int n) // Рекурсивная функция для вычисления n-го числа Фибоначчи
{
    if (n == 1 || n == 2) // Первые два элемента равны 1
        return 1;
    else 
        return fibo(n - 1) + fibo(n - 2); // n-ое число Фибоначчи - сумма двух предыдущих
}

int fib(int n) // Нерекурсивная функция для вычисления n-го числа Фибоначчи
{
    int a, b, sum, k;
    a = k = sum = 0;
    b = 1;
    while (k < n) 
    {
        sum = a + b;
        a = b;
        b = sum;
        k++;
    }
    return a;
}

int main()
{
    int n;
    cout << "n = "; // Ввод n
    cin >> n;
    cout << "rekyrsivn: " << fibo(n) << '\n'; // Вывод n-го числа Фибоначчи(рекурсия)
    cout << "nerekyrsivn: " << fib(n) << '\n'; // Вывод n-го числа Фибоначчи
    system("pause");
    return 0;
}

