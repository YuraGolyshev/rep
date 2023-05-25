#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    vector<int>::iterator iter = min_element(a.begin(), a.end());   // ищем минимальный элемент
    int min = *iter;
    vector<int>::iterator iter2 = remove(a.begin(), a.end(), min); 
    //удалили элементы
    a.erase(iter2, a.end());

    for(vector<int>::iterator it = a.begin(); it != a.end(); it ++) // вывод с итератором
    cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}