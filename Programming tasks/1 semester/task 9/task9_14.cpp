#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int n, x, k = 0, t, m;
cout << "x = "; // Ввод x
cin >> x;
cout << "n = "; // Ввод размера массива
cin >> n;

// Выделение памяти под массив и его заполение
cout << "BBedite massiv\n";
int *a = new int [n*2];
for(int i = 0;i < n;i++)
    cin >> a[i];
for(int i = n;i < n*2;i++)
    a[i] = 0;

// Счетчик нечетных элементов массива
for(int i = 0;i < n;i++)
{
    if(a[i] % 2 != 0)
    k++;             
}

for(int i = 0;i < n+k;i++)
{
    if(a[i] % 2 != 0)   // Проверка на нечетность
    {
        t = a[i+1];         
        a[i+1] = a[i];      
        a[i] = x;   // Вставка x перед элементом
        for(int j = i+1;j < n+k;j++)
        {
            m = a[j+1];     // 
            a[j+1] = t;     // Сдвиг всех элементов массива
            t = m;          //
        }
        i++;
    }
} 

// Вывод массива 
for(int i = 0;i < n+k;i++)
    cout << a[i] << " ";

cout << "\n";
system("pause");
return 0;
}
