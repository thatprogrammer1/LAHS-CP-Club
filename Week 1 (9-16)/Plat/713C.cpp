// Uses the "slope trick" https://codeforces.com/blog/entry/47821
// The basic idea is realizing that the DP solution consists of
// Adding a bunch of absolute value functions, so we can just
// Look at when the DP function changes slope.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    if (fopen("input.in", "r")) {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    int n;
    int a[3000];
    long long ans = 0;
    priority_queue<int> pqueue;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }

    pqueue.push(a[0]);
    for (int i = 1; i < n; i++) {
        pqueue.push(a[i]);
        if (pqueue.top() > a[i]) {
            pqueue.push(a[i]);
            ans += pqueue.top() - a[i];
            pqueue.pop();
        }
    }

    cout << ans << endl;
}
