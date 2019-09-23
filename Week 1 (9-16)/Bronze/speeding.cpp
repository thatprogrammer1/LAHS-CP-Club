#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    if (fopen("speeding.in", "r")) {
        freopen("speeding.in", "r", stdin);
        freopen("speeding.out", "w", stdout);
    }

    int n, m;
    cin >> n >> m;

    int limit[101];
    int speed[101];


    int ni = 1;
    for (int i = 0; i < n; i++) {
        int l, s;
        cin >> l >> s;

        for (int j = 0; j < l; j++) {
            limit[ni+j] = s;
        }

        ni += l;
    }

    int si = 1;
    for (int i = 0; i < m; i++) {
        int l, s;
        cin >> l >> s;

        for (int j = 0; j < l; j++) {
            speed[si+j] = s;
        }

        si += l;
    }

    int over = 0;
    for (int i = 1; i < 101; i++) {
        over = max(over, speed[i]-limit[i]);
    }

    cout << over << "\n";

    return 0;
}