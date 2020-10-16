/*
CodeForces - 1020B - Badge
Solution:

This problem is essentially a depth first search (dfs) problem where you can use
recursion to find the answer. To solve it, you should create a recursive method
that will "visit" the next "node" (which would be the next student). Make sure
to keep track of which students you've already visited so when you visit a
student that has been previously visited, return that as the answer.
*/

#include <bits/stdc++.h>
using namespace std;

#define N 1001

int n, p[N], visited[N];

int dfs(int i) {
    if (visited[i] == 1) return i;  // already visited so this is the answer
    visited[i] = 1;
    return dfs(p[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.in", "r")) {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int a = 1; a <= n; a++) {
        cout << dfs(a) << " ";
        for (int i = 0; i <= n; i++) visited[i] = 0;
    }
    cout << "\n";

    return 0;
}