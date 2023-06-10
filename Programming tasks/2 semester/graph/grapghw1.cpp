#include <iostream>  
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

int main()
{
    vector<set<int>> Gr;		//Cписок смежности
    int n, r;

    cout << "n = "; cin >> n;   // кол-во вершин
    cout << "r = "; cin >> r;   // кол-во ребер

    Gr.resize(n);					
    for (int i = 0; i < r; i++) // заполнение графа
    {
        int x, y;
        cout << "r" << i+1 << " - ";
        cin >> x;  cin >> y;
		if (x > n || y > n) {   // неор
		}
		else {
			Gr[x].insert(y);		
			Gr[y].insert(x);		
		}  
    }

    int v1 = -1, v2 = -1;
    int f = 0;
    for (int i = 0; i < n; ++i)     // нахождение нечетных вершин
    {
        if (Gr[i].size() % 2 == 1)
        {
            if (v1 == -1)
            {
                v1 = i;
            }
            else if (v2 == -1)
            {
                v2 = i;
            }
            else
            {
                f = 1;
                break;
            }
        }
    }

    if (f || v1 != -1 && v2 == -1)  // если нечетных больше чем 2 или 1 пути нет
    {
        cout << f << ' ' << v1 << ' ' << v2 << endl;
        cout << "no Eller's path" << endl;
        return 1;
    }

    vector<int> res;
    stack<int> s;
    if (v1 != -1) s.push(v1);
    else s.push(0);

    while (!s.empty())  // подготовка результата
    {
        int v = s.top();
        if (!Gr[v].size())
        {
            res.push_back(v);
            s.pop();
        }
        else
        {
            int u = *Gr[v].begin();
            Gr[v].erase(u);
            Gr[u].erase(v);
            s.push(u);
        }
    }

    for (int i = 0; i < n; ++i) // проверка связности
        if (Gr[i].size()) 
            f = 1; 

    if (f)  // результат
    {
        cout << "no Eller's path" << endl;
        return 1;
    }
    else
    {
        if (v1 != -1) cout << "Eller's path: ";
        else cout << "Eller's cycle: ";
        for (int i = 0; i < res.size(); i++) 
            cout << res[i] + 1 << ' ';
        cout << endl;
    }
}