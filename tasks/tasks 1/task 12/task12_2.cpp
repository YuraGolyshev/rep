#include<iostream>
using namespace std;

template <typename X>
X **create(X c, int n, int m)   // Создание
{
    X **a = new X *[n];     // Выделение памяти
    for (int i = 0; i < n; i++)
        a[i] = new X [m];
    for (int i = 0; i < n; i++)     // Ввод массива
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

template <typename X>
void print(X **a, int n, int m) // Печать
{    
    for (int i = 0; i < n; i++,cout << endl)
        for (int j = 0; j < m; j++)
        {
            cout.width(2);
            cout << a[i][j] << " ";
        }
}

template<typename X>
X ** change(X **a, int n, int m)    // Замена
{
    for (int j = 0; j < m; j++)
    {
        swap(a[j][0], a[j][m-1]);
        swap(a[j][1], a[j][m-2]);
    }
    return a;
}

int main()
{
    setlocale (LC_ALL, "rus");
    int n,m;
    cout << "BBidite razmernost\n";
    cin >> n >> m;
    char c;
    do
    {
        cout << "BBidite tip:\n1 - int\n2 - double\n3 - char\n4 - float\n";
        int k;
        cin >> k;
        switch(k)   // Вызываем различные типы
        {
            case 1:
            {
                int c = 1;
                int **a = create(c, n, m);
                cout << "INT:\n";
                print (a, n, m);
                a = change(a, n, m);
                cout << "New:\n";
                print (a, n, m);
                break;
            }
            case 2:
            {
                double c1 = 1;
                double **a1 = create(c1, n, m);
                cout << "DOUBLE:\n";
                print (a1, n, m);
                a1 = change(a1, n, m);
                cout << "New:\n";
                print (a1, n, m);
                break;
            }
            case 3:
            {
                char c2 = '1';
                char **a2 = create(c2, n, m);
                cout << "CHAR:\n";
                print (a2, n, m);
                a2 = change(a2, n, m);
                cout << "New:\n";
                print (a2, n, m);
                break;
            }
            case 4:
            {
                float c3 = 1;
                float **a3 = create(c3, n, m);
                cout << "FLOAT:\n";
                print (a3, n, m);
                a3 = change(a3, n, m);
                cout << "New:\n";
                print (a3, n, m);
                break;
            }
            default: cout << "Nepravilno BBedeni dannie\n";
        }
        cout << "ewe raz? Y - da, N - net\n";
        cin >> c;   // Повторяем запуск программы пока не введем N
    }
    while(c != 'N');
    return 0;
}