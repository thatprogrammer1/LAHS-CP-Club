/*
Suppose we have some boolean function e(s) that tells us whether a valid meal
with spiciness <= s exists. It is then obvious that if z is the true minimum
spiciness possible, any s >= z will return as true, while any s < z will return
false. Thus, we can use a binary search for z, moving the upper bound down if
the function returns true and the lower bound up if the function returns false.

The next step is to calculate e(x) in linear time. There are essentially two
approaches: we can either iterate through every sequence where the tastiness >=
m and check if the minimum spiciness <= x, or we can iterate through every
sequence where the spiciness <= s and then check if the tastiness >= m. It turns
out that the second approach is easier, because we can maintain a prefix sum to
calculate the tastiness of any possible meal in constant time. We can then only
check meals that have a spiciness <= s by saving the most recent instance of a
spiciness > x, and starting the meal on the very next index. Then, we iterate
through all bales as the end of the meal, returning true if at any point the
tastiness >= m and reupdating our starting index if the current spiciness > x.
*/

#include <algorithm>
#include <cstdio>
using namespace std;

int n, spice[100001];
long long m, pref_sum[1000001];

bool exists(int s) {
    int prev = 0;
    for (int i = 1; i <= n; i++) {
        if (spice[prev + 1] > s || spice[i] > s)
            prev = i - 1;
        else if (pref_sum[i] - pref_sum[prev] >= m)
            return true;
    }
    return false;
}

int main() {
    if (fopen("hayfeast.in", "r")) {
        freopen("hayfeast.in", "r", stdin);
        freopen("hayfeast.out", "w", stdout);
    }
    scanf("%d%lld", &n, &m);
    int hi = 0;
    pref_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int f;
        scanf("%d%d", &f, &spice[i]);
        hi = max(hi, spice[i]);
        pref_sum[i] = pref_sum[i - 1] + f;
    }
    int lo = 0, mid = hi / 2;
    while (lo < hi) {
        if (exists(mid))
            hi = mid;
        else
            lo = mid + 1;
        mid = (hi + lo) / 2;
    }
    printf("%d\n", lo);
}
