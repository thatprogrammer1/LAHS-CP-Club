/*
Sort the cows by ending time and assign each chicken to the earliest possible
cow, keeping track of which cows have been already paired.
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n, c, chickens[20000];
bool used[20000];
pair<int, int> cows[20000];

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    if (fopen("helpcross.in", "r")) {
        freopen("helpcross.in", "r", stdin);
        freopen("helpcross.out", "w", stdout);
    }
    cin >> c >> n;
    for (int i = 0; i < c; i++) cin >> chickens[i];
    for (int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;
    sort(chickens, chickens + c);
    sort(cows, cows + n, compare);

    int ans = 0;
    for (int i = 0; i < c; i++)
        for (int j = 0; j < n; j++)
            if (!used[j] && cows[j].first <= chickens[i] &&
                chickens[i] <= cows[j].second) {
                ans++;
                used[j] = true;
                break;
            }
    cout << ans << endl;
}
