#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int n, i = 1, t = 0, x;
cout << "n = ";
cin >> n;      // ввод n
while (i <= n) // цикл пока i меньше или равно n
{
    x = t + i + (i - 1); // вычисление квадратов
    t = x;             // сохранение значения x в t
    cout << x << "\n"; // вывод квадрата
    i++;               // увеличение i на 1
}
system ("pause");
return 0;
}