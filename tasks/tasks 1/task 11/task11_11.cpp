#include <iostream>
#include <cmath>
 
using namespace std;

double F(int i, int n) // Рекурсивная функция
{
    if (abs(i - n) < 0.00001)
        return sqrt(n + 1);     // Выход из рекурсии
    else
        return sqrt(1 + i*F(i + 1, n));
}
int main() // Основная функция
{
    double n; // Ввод n
    cout << "n = "; cin >> n;
    cout << F(2, n) << '\n'; // Вызов функции
    system("pause");
    return 0;
}

