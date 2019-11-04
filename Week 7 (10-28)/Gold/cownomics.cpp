#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int n, m, ans;
string spotty[500], plain[500];
map<string, int> h;

bool valid(int l) {
    for (int s = 0; s <= m - l; s++) {
        bool good = true;
        for (int i = 0; i < n; i++) {
            h[spotty[i].substr(s, l)] = s;
        }
        for (int i = 0; i < n; i++) {
            if (h[plain[i].substr(s, l)] == s) {
                good = false;
                break;
            }
        }
        if (good) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    if (fopen("cownomics.in", "r")) {
        freopen("cownomics.in", "r", stdin);
        freopen("cownomics.out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> spotty[i];
    for (int i = 0; i < n; i++) cin >> plain[i];
    int lo = 1, hi = m;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (valid(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}
