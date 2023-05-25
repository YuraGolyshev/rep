#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <string>
 
using namespace std;
 
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
 
bool isSafe(int x, int y) {
    if (x < 0 || y < 0 || x >= 8 || y >= 8) {
        return false;
    }
    
    return true;
}
 
vector<pair<int, int>> path;
 
/**
 * Вывод ответа.
*/
void print(int** board, int x2, int y2, int k) {
    while (k != 0) {
        for (int i = 0; i < 8; i++) {
            if (isSafe(x2 + row[i], y2 + col[i])) {
                if (board[x2 + row[i]][y2 + col[i]] == k) {
                    path.push_back(make_pair(x2 + row[i] + 1, y2 + col[i] + 1));
 
                    x2 = x2 + row[i];
                    y2 = y2 + col[i];
                    k--;
                    break;
                }   
            }
        }
    }
}
 
struct Node {
    int x, y, dist;
 
    Node(int x, int y, int dist = 0)
        : x(x), y(y), dist(dist)
    {}
 
    bool operator<(const Node& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};
 
/**
 * Обход в ширину, поиск длины минимального пути.
*/
int bfs(Node src, Node dest, int** board) {
    set<Node> visited;
 
    queue<Node> q;
    q.push(src);
 
    int hops = 0;
    while (!q.empty()) {
        Node node = q.front();
        
        q.pop();
        int x = node.x;
        int y = node.y;
        int dist = node.dist;
 
        if (x == dest.x && y == dest.y) {
            return dist;
        }
        
        if (!visited.count(node)) {
            visited.insert(node);
            for (int i = 0; i < 8; i++) {
                int x1 = x + row[i];
                int y1 = y + col[i];
                if (isSafe(x1, y1)) {
                    board[x][y] = dist;
                    q.push({x1, y1, dist + 1});
                }
            }
        }
    }
 
    return -1;
}
 
int main() {
    int x1, y1, x2, y2;
    string A, B;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;
 
    x1 = A[0] - 'A';
    y1 = A[1] - '1';
    x2 = B[0] - 'A';
    y2 = B[1] - '1';
 
    int** board = new int*[8];
    for (int i = 0; i < 8; i++) {
        board[i] = new int[8];
    }
 
    Node src = {x1, y1};
    Node dest = {x2, y2};
 
    int k = bfs(src, dest, board) - 1;
 
    cout << k + 1 << endl;  // длина минимального пути
    path.push_back(make_pair(x2, y2));
 
    print(board, x2, y2, k);
    path.push_back(make_pair(x1, y1));  
 
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << (char)(path[i].first + 'A') << " " << path[i].second + 1 << endl;
    }
 
    for (int i = 0; i < 8; i++) {
        delete[] board[i];
    }
 
    delete[] board;
    return 0;
}