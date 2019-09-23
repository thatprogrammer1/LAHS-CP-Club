// Author: Aaron Truong
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
long long a[10000], a_s[10000], dp[10001][10000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a_s[i] = a[i];
    }
    sort(a_s, a_s + n);

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + abs(a_s[0] - a[i - 1]);
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(abs(a_s[j] - a[i - 1]) + dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%lld\n", dp[n][n - 1]);
}
