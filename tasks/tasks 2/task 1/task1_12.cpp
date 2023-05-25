#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int X;
bool kratn(int x) // проверка  
{
    return x % X == 0;
}

int a;
int b;
bool interval(int e) // проверка входит ли значение в [a,b]
{
    return (e >= a && e <= b);
}

int main()
{
    int n1;
    cout << "n1=";
    cin >> n1;
    vector<int> p1; // описали вектор
    int elem;
    cout << "posled 1\n";
    for(int i = 0; i < n1; i++)// заполнили
    {
        cin >> elem; 
        p1.push_back(elem);
    }
    cout << "posled 2\n";
    int n2;
    cout << "n2=";
    cin >> n2;

    vector<int> p2; // описали вектор
    for(int i = 0; i < n2; i++)// заполнили
    {
        cin >> elem; 
        p2.push_back(elem);
    }

    cout << "x=";
    cin >> X;
    vector<int>::iterator it = remove_if(p1.begin(), p1.end(), kratn);  // удаление элементов кратных X в первой последовательности 
    p1.erase(it , p1.end());

    int y;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << "y="; cin >> y;
    replace_if(p2.begin(), p2.end(), interval, y); // Замена элементов, кторые попадают в [a,b] на Y
        
    vector<int> v; // описали вектор
    v.insert(v.begin(), p1.begin(), p1.end()); // объединяем две последовательности 
    v.insert(v.end(), p2.begin(), p2.end());

    sort(v.begin(), v.end()); // сортировка последовательности 

    for(vector<int>::iterator it = v.begin(); it != v.end(); it ++) //вывод с итератором
        cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}