#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n, k, b, id[100002];

bool valid(int rm) {
    if (rm == 0) {
        for (int i = 0; i <= b; i++)
            if (id[i + 1] - id[i] > k) return true;
        return false;
    }
    for (int i = 1; i <= b - rm + 1; i++)
        if (id[i + rm] - id[i - 1] - 1 >= k) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    if (fopen("maxcross.in", "r")) {
        freopen("maxcross.in", "r", stdin);
        freopen("maxcross.out", "w", stdout);
    }
    cin >> n >> k >> b;
    for (int i = 0; i < b; i++) {
        cin >> id[i];
    }
    id[b] = 0, id[b + 1] = n + 1;
    sort(id, id + b + 2);
    int lo = 0, hi = b;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (valid(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << "\n";
}
