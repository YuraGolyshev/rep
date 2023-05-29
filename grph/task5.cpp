#include <iostream>  
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
#include <queue>


using namespace std;

vector<vector<int>> Gr;			//Cписок смежности
vector<int> used;				//Список посещенных вершин
vector<int> path;				//Список вершин составляющих путь
queue<int> buf;					//Список стартовых позиций для обхода в ширину

ifstream in ("input5.txt");

void BFS(int x, int n) {		//Функция обхода в ширину
	used.resize(n, 0);
	path.resize(n);
	for (auto it = path.begin(); it != path.end(); it++)
				cout << *it << ' ';
	used[x] = 1;
	path.push_back(x);
	buf.push(x);

	//bool check = 0;

	while (!buf.empty()) {
		int y = buf.front();
		buf.pop();

		for (int i = 0; i < Gr[y].size(); i++) {	//Проходимся по списку смежности
			if (used[Gr[y][i]] == 0) {			//Мы ещё не посещали данную вершину
				buf.push(Gr[y][i]);
				path[Gr[y][i]] = y;				//позиции = каждому эл-ту списка смежности, на эту позицию записываем предка данной вершины Gr[y][i] (предок = y)
				used[Gr[y][i]] = 1;				//Отмечаем вершину как посещенную
				// if (Gr[y][i] == b) {
				// 	//check = 1;
				// }
				
			}
		}
	}

	for (auto it = path.begin(); it != path.end(); it++)
				cout << *it << ' ';
	//return check;
}

int main()
{
	int n, r, x;

	cout << "n = "; // кол-во вершин
	in >> n;
	cout << n << endl;

	cout << "r = "; // кол-во ребер
	in >> r;
	cout << r << endl;

	Gr.resize(n);					

	while (in.peek() != EOF) {		
		int x, y;
		in >> x >> y;
		if (x > n || y > n) { // ор
		}
		else {
			Gr[x].push_back(y);				
		}
	}

	for (int i = 0; i < n; i++) {	
		sort(Gr[i].begin(), Gr[i].end());
		Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
	}

	cout << "\nsp smewn:\n"; // вывод списка сможности
	for (int i = 0; i < n; i++) {	// вывод содержимого списка смежности
		cout << "x = " << i << ": ";
		for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}
    // cout << "x = ";cin >> x;
    // BFS(x, n);
    // for (auto it = path.begin(); it != path.end(); it++)
	// 		cout << *it << ' ';
    for(int i=0;i<n;i++)
    {
		int count = 0;
		BFS(i, n);
		// for (auto it = path.begin(); it != path.end(); it++)
		// 		cout << *it << ' ';
		cout << endl;
		for(int j=0;j<used.size();j++){
        	if(used[j] == 1)
				count++;
		// cout << used[j] << " ";
		}
		cout << endl;
		if(count==n)
			cout << i << " ";
		cout << endl;
		while (!buf.empty())
    		buf.pop();
		path.clear();
    }
    // for (int i = 0; i < n; i++) {
	// 	int c = 0;

	// 	for (int j = 0; j < n; j++) {
	// 		c += count(Gr[i].begin(), Gr[i].end(), j);	//В счётчик count прибавляем, можно ли попасть из данной вершины в вершину j, и так делаем с каждой вершиной
	// 	}

	// 	cout << "ish_" << i << " = " << c << endl;
	// }
}