#include <iostream>
using namespace std;

int main()
{
int n; // Ввод n
cout << "n = "; cin >> n; 
int m = n;

// Выделение памяти для массивов a, b и c
int *a = new int [n + 1];
int *b = new int [m + 1];
int *c = new int [m + n + 1];

// Заполнение массива a
    cout << "BBedite koef. P(x)" << "\n";
        for (int i = 0; i < n + 1; i++)
            cin >> a[i];

// Вычисление P'(x)
for (int i = 1; i < n + 1; i++)
    b[i-1] = i * a[i];

// Вычисление коэф. P(x) * P'(x)
for (int k = 0; k < m + n; k++)
{
    float s = 0;
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m; j++)
            if (i + j == k) s += a[i]*b[j];
    c[k] = s;
}
// Вывод коэф. P(x) * P'(x)
for (int k = 0; k < m + n; k++) 
    cout << c[k] << " ";

cout << "\n";
system("pause");
return 0;
}
