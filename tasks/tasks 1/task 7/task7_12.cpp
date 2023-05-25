#include <iostream>
#include <cmath>

using namespace std;

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
    int** arr = mas(n, m);
    cout << "old" << "\n";
    out(arr, n, m);
    int a, b, a2, b2 = 0;
    
    // Поиск максимального
    int max = arr[0][0]; 
    int i = 5;
    while(i >=0)
    {
        for (int ryad = 0; ryad < n; ryad++)
        {
            for (int stolb = 0; stolb < m; stolb++)
                if (stolb <= i && arr[ryad][stolb] > max)
                    {
                    max = arr[ryad][stolb]; 
                    a = ryad;
                    b = stolb;
                    }
            i--;
        }    
    }
    // Поиск минимального 
    int min = arr[1][4]; 
    i = 4;
    while(i > 0)
    {
        for (int ryad = 1; ryad < n; ryad++)
        {
            for (int stolb = 0; stolb < m; stolb++)
                if (stolb >= i && arr[ryad][stolb] < min)
                    {
                    min = arr[ryad][stolb];
                    a2 = ryad;
                    b2 = stolb;
                    }
            i--;
        }    
    }
    
    // Замена
    int t = arr[a][b];
    arr[a][b] = arr[a2][b2];
    arr[a2][b2] = t;

    cout << "new\n";
    out(arr, n, m);
    system("pause");
    return 0;
}