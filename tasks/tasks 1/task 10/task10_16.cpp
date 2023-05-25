#include <iostream>
#include <cmath>

using namespace std;

int** mas(int n) // Функция создает массив
{
    // Выделение памяти
    int **arr = new int* [n];     
        for (int a = 0; a < n; a++)
            arr[a] = new int [n]; 
    // Заполнение массива
    cout << "BBedite massiv" << "\n";
        for (int ryad = 0; ryad < n; ryad++)
            for (int stolb = 0; stolb < n; stolb++)
                cin >> arr[ryad][stolb];    
    return arr;
}
void out(int **arr, int n, int k) // Функция выводит массив
{
    for (int ryad = 0; ryad < n; ryad++)
    {
            for (int stolb = 0; stolb < n-k; stolb++)
            {
                cout.width(3);
                cout << arr[ryad][stolb] << " ";
            }
            cout << "\n";
    }
}

int main() // Основная функция
{
    int n, k = 0, i, a, b;
    cout << "n = "; cin >> n;
    int** arr = mas(n);
    cout << "old" << "\n";
    out(arr, n, k);
    
    // Поиск максимального
    int max = arr[0][0]; 
    i = n;
    while(i >=0)
        for (int ryad = 0; ryad < n; ryad++)
        {
            for (int stolb = 0; stolb < n; stolb++)
                if (stolb <= i && arr[ryad][stolb] > max)
                    max = arr[ryad][stolb]; 
            i--;
        }    

    // Удаление стобцов в которых есть max
    for (int stolb = 0; stolb < n; stolb++)
    {
        for (int ryad = 0; ryad < n; ryad++)
            if (arr[ryad][stolb] == max)      // поиск столбца с max
            {    
                i = stolb;
                for (int i = stolb; i < n-1; i++)        // сдвиг всех элементов на место столбца с max 
                    for (int ryad = 0; ryad < n; ryad++)
                        arr[ryad][i] = arr[ryad][i+1];

                for (int ryad = 0; ryad < n; ryad++) // заполение последего столбца 0-ми
                    arr[ryad][n-k-1] = 0;
                k++;
                for (int ryad = 0; ryad < n; ryad++) 
                    if(arr[ryad][i] == max)      // Проверка нет ли в след. столбце max
                    {
                        stolb--;
                        break;
                    }
            }
    }
    cout << "new\n";
    out(arr, n, k);
    system("pause");
    return 0;
}




    