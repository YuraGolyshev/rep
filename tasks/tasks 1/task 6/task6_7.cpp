#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int size, x, y, k;
cout << "BBedite levyju i pravuju granici\n";
cin >> x >> y;  // ввод левой и правой границы
cout << "size = ";
cin >> size;    // ввод размера массива    
int *arr = new int[size];   // выделение памяти под массив 
cout << "BBedite massiv" << "\n";
for (int i = 0; i < size; i++)  // цикл для заполненияя массива
{
    cin >> arr[i];
}
for (int i = 0; i < size; i++) // цикл для проверики соответствия границам и кратности 4-ем
{
    if ((arr[i] % 4 == 0) && arr[i] >= x && arr[i] <= y)
    {
        cout << i << " ";   // вывод номера элемента в массиве
        k++;   // счетчик элеменов подходящих условию
    }
}
if (k == 0) cout << "tikix jelementov net" << "\n"; // если таких элементов нет вывести сообщение об этом
else cout << "\n";    
system("pause");
return 0;
}