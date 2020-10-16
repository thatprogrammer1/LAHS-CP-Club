/*
A far easier question to answer is whether for a given w, an arrangement exists
such that the maximum wait time is at most w. This lends itself to a greedy
solution, as we can simply fill buses as much as possible without exceeding the
maximum wait time. The arrangement then exists only if after all cows are gone,
the number of buses used is at most m.

Now that we know this, how do we relate this to the original problem? Since this
function tells us whether the maximum wait time is at most w, we know that if
the minimum possible w is wf, it will return true for any w >= wf and false for
any w < wf. Thus, we binary search for the solution, knowing that the current w
is an upper bound if the arrangement exists and a lower bound if the arrangement
does not exist. Binary search takes O(log N) time and checking whether an
arrangement exists takes O(N) time, so the overall algorithm runs in O(Nlog N).
*/

#include <algorithm>
#include <cstdio>
using namespace std;

int n, m, c, cows[100000];

bool exists(int w) {
    int st = 0, used = 1;
    for (int i = 0; i < n; i++)
        if (i - st + 1 > c || cows[i] - cows[st] > w) {
            st = i;
            used++;
        }
    return used <= m;
}
int main() {
    if (fopen("convention.in", "r")) {
        freopen("convention.in", "r", stdin);
        freopen("convention.out", "w", stdout);
    }
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 0; i < n; i++) scanf("%d", &cows[i]);
    sort(cows, cows + n);
    int lo = 0, hi = cows[n - 1], mid = hi / 2;
    while (lo < hi) {
        if (exists(mid))
            hi = mid;
        else
            lo = mid + 1;
        mid = (lo + hi) / 2;
    }
    printf("%d\n", lo);
}
