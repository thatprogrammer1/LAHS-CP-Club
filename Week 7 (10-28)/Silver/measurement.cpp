#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int n, g, ans = 0;
map<int, int> amt, at;
set<int, greater<int> > vals;

struct mmt {
    int d, id, c;
    mmt() {}
    bool operator<(const mmt& next) const { return d < next.d; }
} measurements[100000];

int main() {
    ios::sync_with_stdio(false);
    if (fopen("measurement.in", "r")) {
        freopen("measurement.in", "r", stdin);
        freopen("measurement.out", "w", stdout);
    }
    cin >> n >> g;
    vals.insert(g);
    at[g] = n;
    for (int i = 0; i < n; i++) {
        cin >> measurements[i].d >> measurements[i].id >> measurements[i].c;
    }
    sort(measurements, measurements + n);
    for (int i = 0; i < n; i++) {
        int id = measurements[i].id, c = measurements[i].c;
        if (amt.count(id) == 0) amt[id] = g;
        int o = amt[id];
        amt[id] += c;
        if (at.count(amt[id]) == 0) at[amt[id]] = 0;
        at[amt[id]]++;
        at[o]--;
        if ((o == *vals.begin() &&
             (amt[id] <= *(++vals.begin()) || at[o] > 0)) ||
            (o < *vals.begin() && amt[id] >= *vals.begin())) {
            ans++;
        }
        if (at[o] == 0) vals.erase(o);
        vals.insert(amt[id]);
    }
    cout << ans << endl;
}
