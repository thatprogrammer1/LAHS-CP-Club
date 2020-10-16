#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int a, b, x, y;

int main() {
    ios::sync_with_stdio(false);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    cin >> a >> b >> x >> y;
    cout << min(min(abs(a - x) + abs(b - y), abs(a - y) + abs(b - x)),
                abs(a - b))
         << endl;
}
