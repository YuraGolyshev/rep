#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int size, first, mid, n, mid1, mid2;
cout << "size = ";
cin >> size;    // ввод размера массива 
int *arr = new int[size]; // выделения памяти для массива
cout << "BBedite massiv" << "\n";
for (int i = 0; i < size; i++) // цикл для ввода массива
{
    cin >> arr[i];
}
if (size % 2 != 0)  // в случае если кол-во элементов нечетное 
{
    n = size / 2;   // поиск центрального элемента
    first = arr[0]; // первый элемент
    mid = arr[n];   // центральный элемент
    // меняю местами первый и центральный элемент
    arr[0] = mid;   
    arr[n] = first;
}
else                // в случае если кол-во элементов четное 
{
    n = size / 2;       // поиск центрального элемента
    mid1 = arr[n-1];    // первый центральный элемент
    mid2 = arr[n];      // второй центральный элемент
    // меняю местами первый и второй центральные элементы
    arr[n-1] = mid2;    
    arr[n] = mid1;      
}
for (int i = 0; i < size; i++) // вывод получившегося массива
{
    cout << arr[i] << " ";
}
cout << "\n";
system("pause");
return 0;
}