#include <iostream>
#include <cmath>

using namespace std;

int** mas(int n, int b, int m, int i,int d) // Функция создает массив
{
    // Выделение памяти
    int **arr = new int* [n];     
        for (int a = 0; a < n; a++)
            arr[a] = new int [n]; 

    // Заполнение массива
    while(m <= n)
    {
        if(m % 2 != 0) 
            while(i < d)
            {
                int stolb = m-1;
                for (int ryad = 0; ryad < n; ryad++)
                    {
                    arr[ryad][stolb] = i;
                    i++;
                    }
            }
        else
            while(i < d)
            {
                int stolb = m-1;
                for (int ryad = n-1; ryad >= 0; ryad--)
                    {
                    arr[ryad][stolb] = i;
                    i++;                    
                    }
            }
    m++;
    d+=n;
    }
    return arr;
}
    void out(int **arr, int n, int m) // функция выводит массив
{
    // Вывод новго массива
    for (int ryad = 0; ryad < n; ryad++)
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
    int n, b, m = 1, i = 0, d;
    cout << "BBedite n" << "\n" << "n = "; cin >> n;
    b = n * n - 1;
    d = n;
    int** arr = mas(n, b, m, i, d);
    out(arr, n, m);
    system("pause");
    return 0;
}