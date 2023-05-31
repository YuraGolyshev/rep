#include <iostream>
using namespace std;

int main()
{
int n; // Ввод n
cout << "n = "; cin >> n; 

// Выделение памяти для массивов a и b
int *a = new int [n+1];
int *b = new int [n];

// Заполнение массива a
    cout << "BBedite koef. P(x)" << "\n";
        for (int i = 0; i < n + 1; i++)
            cin >> a[i];

// Вычисление P'(x)
for (int i = 1; i < n + 1; i++)
    b[i-1] = i * a[i];

// Вычисление и вывод коэф. P(x) + P'(x)
for (int i = 0; i < n; i++)
{    
    cout << a[i] + b[i] << " ";
}    
cout << a[n];

cout << "\n";
system("pause");
return 0;
}
