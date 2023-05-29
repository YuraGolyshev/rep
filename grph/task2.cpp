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
		if (x > n || y > n) { // неор
		}
		else {
			Gr[x].push_back(y);		
			Gr[y].push_back(x);		
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
    int a, b;
    cout << "a ="; cin >> a;
    cout << "b ="; cin >> b;
    if (auto it = find(Gr[a].begin(), Gr[a].end(), b); it != Gr[a].end()) {
        Gr[a].erase(it);
    }
    if (auto it = find(Gr[b].begin(), Gr[b].end(), a); it != Gr[b].end()) {
        Gr[b].erase(it);
    }

    cout << "\nsp smewn:\n"; // вывод списка сможности
	for (int i = 0; i < n; i++) {	// вывод содержимого списка смежности
		cout << "x = " << i << ": ";
		for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
			cout << *it << ' ';
        }
    cout << endl;
    }
}