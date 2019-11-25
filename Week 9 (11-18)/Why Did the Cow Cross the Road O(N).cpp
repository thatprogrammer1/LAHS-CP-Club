#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n, k, b, ind[100001], dp[100001], ans;

int main() {
    ios::sync_with_stdio(false);
    if (fopen("maxcross.in", "r")) {
        freopen("maxcross.in", "r", stdin);
        freopen("maxcross.out", "w", stdout);
    }
    cin >> n >> k >> b;
    for (int i = 1; i <= n; i++) ind[i] = 0;
    for (int i = 0; i < b; i++) {
        int id;
        cin >> id;
        ind[id] = 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + ind[i];
    ans = b;
    for (int i = k; i <= n; i++) ans = min(ans, dp[i] - dp[i - k + 1]);
    cout << ans << "\n";
}
