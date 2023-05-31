#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int n, x, k = 0, t, m, y;
cout << "x = "; // Ввод x
cin >> x;
cout << "y = "; // Ввод y
cin >> y;
cout << "n = "; // Ввод размера массива
cin >> n;

// Выделение памяти под массив и его заполение
cout << "BBedite massiv\n";
int *a = new int [n*2];
for(int i = 0;i < n;i++)
    cin >> a[i];
for(int i = n;i < n*2;i++)
    a[i] = 0;

// Счетчик элементов массива равных x
for(int i = 0;i < n;i++)
{
    if(a[i] == x)
    k++;             
}

for(int i = 0;i < n+k;i++)
{
    if(a[i] == x)   // Проверка не равен ли элемент x
    {
        t = a[i+1];         
        a[i+1] = a[i];      
        a[i] = y;   // Вставка y перед элементом
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
