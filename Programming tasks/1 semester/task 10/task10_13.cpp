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
    for (int ryad = 0; ryad < n-k; ryad++)
    {
            for (int stolb = 0; stolb < n; stolb++)
            {
                cout.width(3);
                cout << arr[ryad][stolb] << " ";
            }
            cout << "\n";
    }
}

int main() // Основная функция
{
    int n, k = 0, x, i;
    cout << "n = "; cin >> n;
    cout << "x = "; cin >> x;
    int** arr = mas(n);
    cout << "old" << "\n";
    out(arr, n, k);
    
    // Удаление строк в которых есть x
    for (int ryad = 0; ryad < n; ryad++)
    {
        for (int stolb = 0; stolb < n; stolb++)
            if (arr[ryad][stolb] == x)      // поиск строки с x
            {    
                i = ryad;
                for (int i = ryad; i < n-1; i++)        // сдвиг всех элементов на место строки с x 
                    for (int stolb = 0; stolb < n; stolb++)
                        arr[i][stolb] = arr[i+1][stolb];

                for (int stolb = 0; stolb < n; stolb++) // заполение последней строки 0-ми
                    arr[n-k-1][stolb] = 0;
                k++;
                for (int stolb = 0; stolb < n; stolb++) 
                    if(arr[i][stolb] == x)      // Проверка нет ли в след. строке элемента x
                    {
                        ryad--;
                        break;
                    }
            }
    }
    cout << "new\n";
    out(arr, n, k);
    system("pause");
    return 0;
}




    