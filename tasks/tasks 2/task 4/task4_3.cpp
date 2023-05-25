#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int razmernost() // считываем размерность
{
    int n;
    in >> n;
    return n;
}

int razryad(vector<vector<int>> &a, int n) // функция для поиска кол-ва разрядов
{
    int max = a[0][0];
    for (int i = 0; i < n; i++)     
        for (int j = 0; j < n; j++)
            if(a[i][j] > max)
                max = a[i][j];
    int k = 0;
    while(max > 0)
    {
        max/=10;
        k++;
    }
    return k;
}

int st(int x, int y)    // функция степени
{
    for(int i = 1;i < y;i++)
        x*=x;
    return x;
}

void porazryad_sort(vector<vector<int>> &a, int n)      // сортировка поразрядная
{ 
    int p = 10;
    int k = razryad(a, n);
    vector<vector<int>>vec; // создаем p доп векторов
    vec.resize(p); 
    vector<int>res;
    for(int j=0; j < n;j++) // идем по столбцам
        for(int i=0;i < k;i++)  // i - разряд
        {
            for(int s=0; s < n;s++)
            {
                int b = (a[s][j] / st(p,i)) % p; // считаем в какой вектор попадет элемент
                vec[b].push_back(a[s][j]);  // записываем в вектор
            }
            for(int m=0; m < p;m++)
            {
                res.insert(res.begin(), vec[m].begin(), vec[m].end()); // объединяем вектора
            }
            for(int g=0;g<n;g++) // записываем res в нужный столбец a
                a[g][j] = res[g];
            vec.clear();    // очищаем вектора
            res.clear();
            vec.resize(p);
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
    porazryad_sort(a, n);
    for (int i = 0; i < n; i++) // Цикл, который идёт по строкам
    {
        for (int j = 0; j < n; j++) // Цикл, который идёт по элементам
            out << setw(4) << a[i][j] << " ";
        out << endl;
    }
    cout << "sorted!" << endl;
    system("pause");
    return 0;
}