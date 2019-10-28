#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int i, j, d, step;
    node() {}
    node(int a, int b, int c, int e) {
        i = a;
        j = b;
        d = c;
        step = e;
    }

    bool operator<(const node& next) const { return d > next.d; }
};
int n, t, graph[101][101], dist[101][101][3];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void dijkstra() {
    priority_queue<node> pq;
    dist[0][0][0] = 0;
    pq.push(node(0, 0, 0, 0));

    while (!pq.empty()) {
        node curr = pq.top();
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int ni = curr.i + di[i], nj = curr.j + dj[i];
            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            int time = t + (curr.step % 3 == 2 ? graph[ni][nj] : 0),
                n_step = (curr.step + 1) % 3;
            if (dist[ni][nj][n_step] > dist[curr.i][curr.j][curr.step] + time) {
                dist[ni][nj][n_step] = dist[curr.i][curr.j][curr.step] + time;
                pq.push(node(ni, nj, dist[ni][nj][n_step], n_step));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    if (fopen("visitfj.in", "r")) {
        freopen("visitfj.in", "r", stdin);
        freopen("visitfj.out", "w", stdout);
    }
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            for (int k = 0; k < 3; k++) dist[i][j][k] = 1000000000;
        }
    }
    dijkstra();
    cout << min(dist[n - 1][n - 1][0],
                min(dist[n - 1][n - 1][1], dist[n - 1][n - 1][2]))
         << endl;
}
