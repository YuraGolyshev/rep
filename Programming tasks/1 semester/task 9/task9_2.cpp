#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int n, x, e = 0, k = 0;
cout << "x = "; // Ввод x
cin >> x;
if (x == 0)
    e = 1;
cout << "n = "; // Ввод размера массива
cin >> n;

// Выделение памяти под массив и его заполение
cout << "BBedite massiv\n";
int *a = new int [n];
for(int i = 0;i < n;i++)
    cin >> a[i];


for(int i = 0;i < n;i++)
{
    if(a[i] == x)   // Проверка не равен ли элемент x
    {
        for(int j = i+1;j < n;j++)
            a[j-1] = a[j];  // Сдвиг всех элементов
        a[n-1-k] = e;   // Добавление в конце 0(или 1, если x равен 0)
        k++;    // Счетчик элементов равных x
        if(a[i] == x)   // Проверка не равен ли след. элемент x
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
