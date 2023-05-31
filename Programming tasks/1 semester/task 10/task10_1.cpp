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
    for (int ryad = 0; ryad < n+k; ryad++)
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
    int i, n, m, k = 0;
    cout << "n = "; cin >> n;
    int* arrx = X(n);
    int** arr = mas(n);
    cout << "old" << "\n";
    out(arr, n, k);
    
    // Вставка строки X после положительных строк
    for (int ryad = 0; ryad < n*2; ryad++)
    {
        m = 0;
        for (int stolb = 0; stolb < n; stolb++)
            if(arr[ryad][stolb] > 0)
                m++; // Счетчик подходящих элементов
        if(m == n)
        {
            i = ryad;
            
            // Сдивг всех строк начиная с конца 
            for (int ryad = n+k; ryad > i; ryad--)          
                for (int stolb = 0; stolb < n; stolb++)
                    arr[ryad+1][stolb] = arr[ryad][stolb];

            // Вставка X после положительной строки
            for (int stolb = 0; stolb < n; stolb++)         
                arr[i+1][stolb] = arrx[stolb];     
            k++;    // счетчик вставленных строк
        }
    }

    cout << "new\n";
    out(arr, n, k);
    system("pause");
    return 0;
}




    