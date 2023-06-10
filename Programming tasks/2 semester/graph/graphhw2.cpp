#include <iostream>  
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

vector<vector<int>>Gr;  //Cписок смежности
vector<int> used, a;

void dfs(int v)
{
	used[v] = 1;
	for (auto u : Gr[v])
		if (!used[u]) 
            dfs(u);
	a.push_back(v);
}

int main()
{
    int n, r;

    cout << "n = "; cin >> n;   // кол-во вершин
    cout << "r = "; cin >> r;   // кол-во ребер

    Gr.resize(n); used.assign(n, 0);					
    for (int i = 0; i < r; i++) // заполнение графа
    {
        int x, y;
        cout << "r" << i+1 << " - ";
        cin >> x;  cin >> y;
		if (x > n || y > n) // ор.
        {
        }   
		else Gr[x].push_back(y);				
    }

    for (int i = 0; i < n; i++) // вызываем dfs для всех непосещенных вершин
		if (!used[i]) 
            dfs(i);

	for (int i = n - 1; i >= 0; i--) cout << a[i] << ' ';   // результат
	cout << endl;
    system("Pause");										
	return 0;												
}