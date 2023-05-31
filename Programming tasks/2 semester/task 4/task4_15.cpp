#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output3.txt");

int razmernost() // считываем размерность
{
    int n;
    in >> n;
    return n;
}

void vst_sort(vector<int> &x, int n)    // сортировка вставками
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && x[j] < x[j - 1])
        {
            swap(x[j], x[j - 1]);
            j--;
        }
    }
}
void d_sort(vector<vector<int>> &a, int n)      // сортировка побочных диагоналей
{ 
    vector<int> diagonal; // создаем вектор
    for(int k=1; k < 2*n - 1;k++)   // диагонали
    {
        for(int i=0;i<n;i++)
            if(k-i<n && k-i>=0)
                diagonal.push_back(a[i][k-i]); // заполняем вектор
        vst_sort(diagonal, diagonal.size()); // сортируем полученный вектор 
        int L=0;
        for(int i=0;i<n;i++)
            if(k-i<n && k-i>=0)
            {
                a[i][k-i] = diagonal[L]; 
                L++;
            }
        diagonal.clear(); // очищаем вектор
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
    d_sort(a, n);
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