/*
This problem is similar to a normal maze solving problem, with extra
constraints. The main key difference is that we have to store whether Bessie
smells like oranges. This can be done by adding an extra state to the 1000 x
1000 grid.

This is really old code so it is very messy.
*/
#include <bits/stdc++.h>
using namespace std;
#define LEN 1010
int maze[LEN][LEN];
struct cow {
    int a, b;
    int t;
    bool smell;
    cow(int a, int b, int t, bool smell) : a(a), b(b), t(t), smell(smell) {}
};
bool visit[LEN][LEN][2];
bool operator<(cow a, cow b) { return a.t > b.t; }
int main() {
    ios::sync_with_stdio(false);
    // freopen("test.txt","r",stdin);
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int c = 1; c <= M; c++) {
            cin >> maze[i][c];
        }
    }

    priority_queue<cow> next;
    cow temp = cow(1, 1, 0, false);
    next.push(temp);
    int ans = -1;
    while (!next.empty()) {
        temp = next.top();
        next.pop();
        int smellIndex = (temp.smell) ? 1 : 0;
        if (visit[temp.a][temp.b][smellIndex]) continue;
        visit[temp.a][temp.b][smellIndex] = true;
        if (temp.a == N && temp.b == M) {  // Goal
            ans = temp.t;
            break;
        }
        // Expand
        for (int i = -1; i <= 1; i++) {
            for (int c = -1; c <= 1; c++) {
                if (i != 0 && c != 0) continue;
                if (i == 0 && c == 0) continue;
                cow f = cow(temp.a + i, temp.b + c, temp.t, temp.smell);

                if (visit[f.a][f.b][smellIndex]) continue;  // If visited
                if (maze[f.a][f.b] == 0) continue;
                if (maze[f.a][f.b] == 1) {
                    f.t = temp.t + 1;
                    next.push(f);
                }
                if (maze[f.a][f.b] == 2) {
                    f.t = temp.t + 1;
                    f.smell = true;
                    next.push(f);
                }
                if (maze[f.a][f.b] == 3) {
                    if (temp.smell) {
                        f.t = temp.t + 1;
                        f.smell = true;
                        next.push(f);
                    }
                }
                if (maze[f.a][f.b] == 4) {
                    f.smell = false;
                    f.t += 1;
                    while (true) {
                        if (maze[f.a][f.b] == 0 || maze[f.a][f.b] == 3) {
                            f.a -= i;
                            f.b -= c;
                            f.t -= 1;
                            if (visit[f.a][f.b][0]) break;
                            next.push(f);
                            break;
                        }
                        if (maze[f.a][f.b] == 1 || maze[f.a][f.b] == 2) {
                            if (maze[f.a][f.b] == 2) f.smell = true;
                            if (f.smell)
                                smellIndex = 1;
                            else
                                smellIndex = 0;
                            if (visit[f.a][f.b][smellIndex]) break;
                            next.push(f);
                            break;
                        }
                        f.a += i;
                        f.b += c;
                        f.t += 1;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
