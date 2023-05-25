#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int x, size, s = 0;
cout << "x = ";
cin >> x;   // ввод x
cout << "size = ";
cin >> size;    // ввод размера массива 
int *arr = new int[size];   // выделение памяти под массив 
cout << "BBedite massiv" << "\n";
for (int i = 0; i < size; i++) // цикл для заполненияя массива
{
    cin >> arr[i];
}
for (int i = 0; i < size; i++) // цикл для проверки соответствия условия "нечетных элементов, меньших x"
{
    if (arr[i] % 2 != 0 && arr[i] < x)
    s += arr[i]; // подсчет суммы
}
if (s != 0) cout << s << "\n"; // если сумма не равна 0 вывод суммы
else cout << "tikix jelementov net" << "\n"; // если сумма равна 0, таких элементов нет
system("pause");
return 0;
}