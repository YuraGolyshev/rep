#include <iostream>  
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

vector<vector<int>> Gr;			//Cписок смежности
vector<int> used;				//Список посещенных вершин
vector<int> path;				//Список вершин составляющих путь

ifstream in ("input.txt");

void depth(int x, int n) {		//Функция обхода в глубину

	used.resize(n);
	used[x] = 1;
	path.push_back(x);

	for (int i = 0; i < Gr[x].size(); i++) {
		if (used[Gr[x][i]] == 0) {
			depth(Gr[x][i], n);
		}
    }
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
		sort(Gr[i].begin(), Gr[i].end());// Сортируем все строки вектора
		Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());// Удаляем дубликаты
	}

	cout << "\nsp smewn:\n"; // вывод списка сможности
	for (int i = 0; i < n; i++) {	
		cout << "x = " << i << ": ";
		for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}
    cout << "x = ";cin >> x;
    depth(x, n);
    for(int i=0;i<used.size();i++)// получается, если в used нули то вершины с номерами этих элементов нам подходят
    {
        if(used[i] == 0)
            cout << i << " ";
    }
}