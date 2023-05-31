#include <iostream>
#include <cmath>

using namespace std;


int* X(int n) // Функция создает строку
{
    // Выделение памяти для массива X
    int *arrx = new int [n];
    // Заполнение массива X
    cout << "BBedite X" << "\n";
        for (int ryadx = 0; ryadx < n; ryadx++)
            cin >> arrx[ryadx];
    return arrx;
}

int** mas(int n) // Функция создает массив
{
    // Выделение памяти
    int **arr = new int* [n*2];     
        for (int a = 0; a < n*2; a++)
            arr[a] = new int [n*2]; 
    // Заполнение массива
    cout << "BBedite massiv" << "\n";
        for (int ryad = 0; ryad < n; ryad++)
            for (int stolb = 0; stolb < n; stolb++)
                cin >> arr[ryad][stolb];    
    // Заполение 0-ми пустой части массива
        for (int ryad = 0; ryad < n*2; ryad++)
            for (int stolb = 0; stolb < n*2; stolb++)
                if(stolb >= n || ryad >= n)
                    arr[ryad][stolb] = 0;
    return arr;
}
void out(int **arr, int n, int k) // Функция выводит массив
{
    for (int ryad = 0; ryad < n; ryad++)
    {
            for (int stolb = 0; stolb < n+k; stolb++)
            {
                cout.width(3);
                cout << arr[ryad][stolb] << " ";
            }
            cout << "\n";
    }
}

int main() // Основная функция
{
    int i, n, m, k = 0, y;
    cout << "n = "; cin >> n;
    cout << "y = "; cin >> y;
    int* arrx = X(n);
    int** arr = mas(n);
    cout << "old" << "\n";
    out(arr, n, k);
    
    // Вставка X перед положительными столбцами
    for (int stolb = 0; stolb < n*2; stolb++)
    {
        m = 0;
        for (int ryad = 0; ryad < n; ryad++)
            m = m + arr[ryad][stolb];   // Сумма элементов столбца
        if ((m != 0) && (m % y == 0))
        {
            i = stolb;

            // Сдивг всех столбцов начиная с конца 
            for (int stolb = n+k; stolb >= i; stolb--)          
                for (int ryad = 0; ryad < n; ryad++)
                    arr[ryad][stolb+1] = arr[ryad][stolb];

            // Вставка X перед столбцом кратным y
            for (int ryad = 0; ryad < n; ryad++)         
                arr[ryad][i] = arrx[ryad];     
            k++;    // счетчик вставленных столбцов
            stolb++;
        }
    }

    cout << "new\n";
    out(arr, n, k);
    system("pause");
    return 0;
}




    