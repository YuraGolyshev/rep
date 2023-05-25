#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output2.txt");

int razmernost() // считываем размерность
{
    int n;
    in >> n;
    return n;
}

void rascheska_sort(vector<vector<int>> &a, int n)      // сортировка расческой
{ 
    double gap = n/1.247; // n/f
    while(gap >= 1)
    {
        if(gap < 1)
            gap = 1;
        for(int j=0;j < n;j++) // идем по столбцам
            for(int i=0;i < n-gap;i++)
            {
                if((j+1) % 3 == 0) // случай для каждого 3-го столбца
                {
                    if(a[i][j] < a[i+gap][j]) // сравниваем 
                        swap(a[i][j], a[i+gap][j]); // меняем местами
                }
                else                // для остальных
                {
                    if(a[i][j] > a[i+gap][j])  // сравниваем 
                        swap(a[i][j], a[i+gap][j]); // меняем местами
                }
            }
        gap /= 1.247; // уменьшаем расстояние в f раз
    }

}

int main()
{
    int n = razmernost();  // Размер вектора
    vector<vector<int>>a(n, vector <int> (n)); // Объявление вектора на n строк по n элементов 
    while (in.peek() != EOF) 
    {       
    for (int i = 0; i < n; i++)     // Цикл, который идёт по строкам
        for (int j = 0; j < n; j++) // Цикл, который идёт по элементам
        {
            in >> a[i][j]; // Заполнение вектора или массива
        }
    }
    rascheska_sort(a, n);
    for (int i = 0; i < n; i++) // Цикл, который идёт по строкам
    {
        for (int j = 0; j < n; j++) // Цикл, который идёт по элементам
            out << setw(4) << a[i][j] << " "; // Вывод элементов i строки вектора
        out << endl;
    }
    cout << "sorted!" << endl;
    system("pause");
    return 0;
}