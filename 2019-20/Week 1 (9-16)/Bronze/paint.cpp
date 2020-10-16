#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    if (fopen("paint.in", "r")) {
        freopen("paint.in", "r", stdin);
        freopen("paint.out", "w", stdout);
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int smallest = min(a, c);
    int biggest = max(b, d);

    int wall[101] = {0};

    for (int i = smallest; i <= biggest; i++) {
        if (i > a && i <= b) {
            wall[i] = 1;
        }
        if (i > c && i <= d) {
            wall[i] = 1;
        }
    }

    int counter = 0;
    for (auto el : wall) {
        if (el == 1) counter++;
    }

    cout << counter << "\n";

    return 0;
}