#include <iostream>  
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in ("input.txt");

int main()
{
vector<vector<int>> Gr;			//Cписок смежности
	int n, r;

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
    
    for (int i = 0; i < n; i++) {
		int c = 0;

		for (int j = 0; j < n; j++) {
			c += count(Gr[i].begin(), Gr[i].end(), j);	// считаем, если из данной вершины можно попасть в вершину j
		}

		cout << "ish_" << i << " = " << c << endl;
	}
}