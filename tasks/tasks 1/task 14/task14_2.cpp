#include <iostream>
#include<math.h>

using namespace std;

struct point //структура точка
{
    double x, y;
};

point *create(int &n) //создание массива точек
{
    cout << "n = ";
    cin >> n;
    point *a = new point[n]; //массив точек
    for(int i = 0; i < n; i++)
    {
        cout << "Input " << i << " point coordinates (x, y): \n";
        cin >> a[i].x >> a[i].y;
    }
    return a;
}


int kol(point *a, int n) // функция для поиска макс. кол-ва точек на прямой
{
    int kol = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            double k = (a[j].y - a[i].y) / (a[j].x - a[i].x); //k = y2-y1/x2-x1
            double b =(a[j].x * a[i].y - a[i].x * a[j].y) / (a[j].x - a[i].x);    //b = x2y1-x1y2/x2-x1
            int kol = 2; // обнуляем
            for(int u = 0; u < n; u++)
                if(a[u].y == k * a[u].x + b && a[u].x != a[i].x && a[u].x != a[j].x && a[u].y != a[i].y && a[u].y != a[j].y)    // если y = kx + b
                {
                    kol++; 
                    if(kol > max)   // ищем максимальное
                        max = kol; 
                }
        }
    return max;
}

int main()
{
    int n;
    point *a = create(n);
    cout << "max dots " << kol(a, n) << endl;
    system("pause");
    return 0;
}