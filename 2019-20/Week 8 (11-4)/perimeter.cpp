#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n, max_a = 0, fin_p = 1000000000, curr_a = 0, curr_p = 0;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char graph[1000][1000];
bool vis[1000][1000];

void traverse(int x, int y) {
    curr_a++;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || graph[nx][ny] == '.')
            curr_p++;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && graph[nx][ny] == '#') {
            if (!vis[nx][ny]) traverse(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) graph[i][j] = row[j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == '#' && !vis[i][j]) {
                traverse(i, j);
                if (curr_a > max_a) {
                    max_a = curr_a;
                    fin_p = curr_p;
                } else if (curr_a == max_a)
                    fin_p = min(curr_p, fin_p);
                curr_a = 0, curr_p = 0;
            }
        }
    }
    cout << max_a << " " << fin_p << endl;
}
