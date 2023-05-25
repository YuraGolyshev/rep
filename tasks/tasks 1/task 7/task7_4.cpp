#include <iostream>
#include <cmath>

using namespace std;

int* X(int n) // Функция создает массив X
{
    // Выделение памяти для массива X
    int *arrx = new int [n];
    // Заполнение массива X
    cout << "BBedite X" << "\n";
        for (int ryadx = 0; ryadx < n; ryadx++)
            cin >> arrx[ryadx];
    return arrx;
}

int** mas(int n, int m) // Функция создает массив
{
    // Выделение памяти
    int **arr = new int* [n];     
        for (int a = 0; a < n; a++)
            arr[a] = new int [n]; 
    // Заполнение массива
    cout << "BBedite massiv" << "\n";
        for (int ryad = 0; ryad < n; ryad++)
            for (int stolb = 0; stolb < m; stolb++)
                cin >> arr[ryad][stolb];
    return arr;
}

void out(int **arr, int n, int m) // Функция выводит массив
{
    for (int ryad = 0; ryad < n; ryad++)
    {
        for (int stolb = 0; stolb < m; stolb++)
        {
            cout.width(3);
            cout << arr[ryad][stolb] << " ";
        }
        cout << "\n";
    }
}

int main() // Основная функция
{
    int n, m;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    int* arrx = X(n);
    int** arr = mas(n, m);
    cout << "old" << "\n";
    out(arr, n, m);
    // Замена четных строк
    for (int stolb = 0; stolb < m; stolb++)
            for (int ryad = 0; ryad < n; ryad++)
            {
                if (ryad == 0 || ryad % 2 == 0)
                    for (int ryadx = 0; ryadx < n; ryadx++)
                    {
                        arr[ryad][stolb] = arrx[ryadx];
                    }
            }
    cout << "new\n";
    out(arr, n, m);
    system("pause");
    return 0;
}

