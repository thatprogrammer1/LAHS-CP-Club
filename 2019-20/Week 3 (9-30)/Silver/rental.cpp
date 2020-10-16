
// C++ Implementation

#include <bits/stdc++.h>
using namespace std;

int n, m, r, si = 0, cows[100001], rentals[100001];
pair<int, int> stores[100001];

int sell(int c, bool assign) {
    int amt = cows[c], loc[100001], s = si;
    long long total = 0;
    while (amt > 0 && s < m) {
        loc[s] = stores[s].second;
        int sub = min(amt, loc[s]);
        total += sub * stores[s].first;
        amt -= sub;
        loc[s] -= sub;
        if (assign) stores[s].second = loc[s];
        if (loc[s] == 0) s++;
    }
    if (assign) si = s;
    return total;
}

int main() {
    if (fopen("rental.in", "r")) {
        freopen("rental.in", "r", stdin);
        freopen("rental.out", "w", stdout);
    }

    long long ans = 0;
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < n; i++) scanf("%d", &cows[i]);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &stores[i].second, &stores[i].first);
    for (int i = 0; i < r; i++) scanf("%d", &rentals[i]);

    sort(cows, cows + n, greater<int>());
    sort(stores, stores + m, greater<pair<int, int> >());
    sort(rentals, rentals + r);

    int ri = 0;
    for (int ci = 0; ci < n; ci++) {
        if (ci < n - r || sell(ci, false) > rentals[ri]) {
            ans += sell(ci, true);
            ri = ci - (n - r) + 1;
        } else
            break;
    }
    for (; ri < r; ri++) ans += rentals[ri];
    printf("%lld\n", ans);
}
