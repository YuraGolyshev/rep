#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> used(8, vector<int>(8, 0));

vector<vector<pair<int, int>>> p(8, vector<pair<int, int>>(8, { -1,-1 }));
// Ходы коня
vector<pair<int, int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

struct q
{
    pair<int,int> x;
    q* next;
};

void pushq(q*& e, q*& s, pair<int,int> el)
{
    q* add = new q;
    add->x = el;
    add->next = NULL;
    if (e == NULL)
    {
        s = add;
        e = add;
    }
    else
    {
        e->next = add;
        e = add;
    }
}

pair<int,int> topq(q*& e, q*& s)
{
    q* top = s;
    return top->x;
}

pair<int,int> popq(q*& e, q*& s)
{
    q* top = s;
    pair<int,int> x = top->x;
    s = s->next;
    if (!s)
        e = NULL;
    delete top;
    return x;
}

bool emptyq(q*& e, q*& s)
{
    return e == NULL;
}

void BFS(pair<int,int>& st, pair<int,int>& fin)
{
    // Создаем и добавляем в очередь стартовую вершину
    q* e = NULL;
    q* s = NULL;
    pushq(e, s, st);
    used[st.first][st.second] = 1;
    // Пока не пуста
    while (!emptyq(e, s))
    {
        pair<int,int> v = popq(e,s);
        int row = v.first, col = v.second;
        if (v == fin) return;
        // Проходимся по всем ходам коня
        for (auto move : dir)
        {
            int row1 = row + move.first;
            int col1 = col + move.second;
            // Если получающийся ход попадает в шахматную доску
            if (row1 >= 0 && row1 <= 7 && col1 >= 0 && col1 <= 7 && !used[row1][col1])
            {
                // Добавляем в очередь, 
                pushq(e, s, { row1,col1 });
                // Обозначаем посещенную вершину
                used[row1][col1] = 1;
                // Записываем предка
                p[row1][col1] = {row,col};
            }
        }
    }
}

int main()
{
    string a, b;
    cout << "BBedite A:\n"; cin >> a;
    cout << "BBedite B:\n"; cin >> b;

    pair<int, int> st = {a[0] - 'A', a[1] - '1'};
    pair<int, int> fin = {b[0] - 'A', b[1] - '1'};
    BFS(st, fin);
    pair<int, int> v = fin;
    vector<pair<int, int>> res;
    // Проходимся по предкам от B, пока не дойдём до A
    while (v.first != -1)
    {
        res.push_back({v.first,v.second});
        v = p[v.first][v.second];
    }
    // Путь в обратном порядке, поэтому разворачиваем
    reverse(res.begin(), res.end());
    for (auto t : res)
        cout << char(t.first + 'A') << t.second + 1 << ' '; // Путь
}
