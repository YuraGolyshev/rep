#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int size, k, min;
cout << "size = ";
cin >> size;    // ввод размера массива
int *arr = new int[size];   // выделение памяти под массив 
cout << "BBedite massiv" << "\n";
for (int i = 0; i < size; i++)  // цикл для заполненияя массива
{
    cin >> arr[i];
}
for (int i = 0; i < size; i++)  // цикл для поиска первого элемента, который не равен нулю
{
    if (arr[i] != 0)
    {
        min == arr[i]; 
        break;
    }
}
for (int i = 0; i < size; i++) // цикл для посика минимального элемента 
{
    if (arr[i] < min && arr[i] != 0) min = arr[i];
}
for (int i = 0; i < size; i++) // цикл для вывода номеров минимальных элементов
{
    if (arr[i] == min && arr[i] != 0) // если элемент равен минимальному и не 0, вывести его номер в массиве
    {
        if (arr[i] % 2 != 0)    // проверка на нечетность 
            {
            cout << i << " ";   // вывод номера элемента в массиве
            k ++; // счетчик подходящих элементов
            }
    }
}
if (k == 0) cout << "nechetnyh jelementov net" << "\n"; // если таких элементтов нет вывести сообщение об этом
else cout << "\n";
system("pause");
return 0;
}