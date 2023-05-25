#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool chetn(int c) // проверка четности 
{
    return c % 2 == 0;
}

int main()
{
    int n;
    cout << "n=";
    cin >> n;
    vector<int> a;  // описали вектор
    int elem;
    for(int i = 0; i < n; i++)  // заполнили
    {
        cin >> elem; 
        a.push_back(elem);
    }

    vector<int>::iterator iter = max_element(a.begin(), a.end());   // ищем max элемент
    int max = *iter;
    vector<int>::iterator iter2 = remove(a.begin(), a.end(), max); 
    // удалили элементы
    a.erase(iter2, a.end());

    int x = 99;
    for(int i = 0; i < a.size(); i++) // после элементов кратных 2 вставляем новый
        if(a[i] % 2 == 0)
        {
            a.insert(a.begin() + i + 1, x);
            i++;
        }

    sort(a.begin(), a.end()); // сортируем последовательность 

    vector<int>::iterator iter3 = unique(a.begin(), a.end());   // удаляем повторяющиеся элементы 
    a.erase(iter3, a.end());

    for(vector<int>::iterator it = a.begin(); it != a.end(); it ++) // вывод с итератором
        cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}

