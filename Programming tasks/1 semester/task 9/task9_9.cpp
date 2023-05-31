#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int n, x, e = 0, k = 0;
cout << "x = "; // Ввод x
cin >> x;
cout << "n = "; // Ввод размера массива
cin >> n;

// Выделение памяти под массив и его заполение
cout << "BBedite massiv\n";
int *a = new int [n];
for(int i = 0;i < n;i++)
    cin >> a[i];


for(int i = 0;i < n;i++)
{
    if((a[i] % 2 == 0) && (a[i] % x == 0))   // Проверка на четность и кратность x
    {
        for(int j = i+1;j < n;j++)
            a[j-1] = a[j];  // Сдвиг всех элементов
        a[n-1-k] = 1;   // Добавление в конце 1
        k++;    // Счетчик четных и кратных x элементов 
        if((a[i] % 2 == 0) && (a[i] % x == 0))   // Проверка на четность и кратность x след. элемента
            i--;
    }
} 

// Вывод массива 
for(int i = 0;i < n-k;i++)
    cout << a[i] << " ";

cout << "\n";
system("pause");
return 0;
}
