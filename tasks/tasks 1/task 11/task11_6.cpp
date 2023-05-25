#include <iostream>
#include <cmath>
 
using namespace std;

int polinom(int x, int n) // Рекурсивная функция для вычисления полинома
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 2*x;
    if(n > 1)
        return 2*x*polinom(x, n-1) - 2*(n-1)*polinom(x, n-2);
}

int factorial(int n) // Вычисление факториала
{
    if(n == 0)
        return 1;
    else
        return factorial(n - 1) * n;
}

int main()
{
    int x, n, sum = 0;
    cout << "n = "; // Ввод n
    cin >> n;
    cout << "x = "; // Ввод x
    cin >> x;
    for(int i = 0; i <= n/2; i++)
        sum += pow(-1, i) * (factorial(n) / (factorial(i) * factorial(n - 2 * i))) * pow(2 * x, n - 2 * i); // Вычисление без рекурсии
    cout << "nerekyrsivn: " << sum << '\n';         // Вывод результата без ииспользования рекурсии
    cout << "rekyrsivn: " << polinom(x, n) << '\n'; // Вывод результат с использованием рекурсии
    system("pause");
    return 0;
}

