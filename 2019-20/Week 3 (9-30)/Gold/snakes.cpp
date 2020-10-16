/*
This problem is solved through dynamic programming. Let dp be a function where
dp(i, j) equals the minimum cost to capture the first i snakes in j moves.
Clearly, the final answer will then be dp(n, k).

dp(i, j) = min(cost(0, j-1, i)...cost(i-1, j-1, i)) where cost(l, j, i) = dp(l,
j) + max(snake[l+1]...snake[i])*(i-l) - sum(snake[l+1]...snake[i]).

For each dp(i, j), we iterate l from i-1...0 to find the cost for each l. To do
so, we update max(snake[l+1]...snake[i]) and sum(snake[l+1]...snake[i]) for each
l in order to calculate cost in constant time. Thus, the time complexity is
O(KN^2), which is fast enough to solve this problem.
*/
// C++ Implementation

#include <algorithm>
#include <cstdio>
using namespace std;

#define INF 1000000000

int n, k;
int list[400], dp[401][400], mx[401];

int main() {
    if (fopen("snakes.in", "r")) {
        freopen("snakes.in", "r", stdin);
        freopen("snakes.out", "w", stdout);
    }
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
        mx[i + 1] = max(mx[i], list[i]);
    }
    for (int i = 1; i <= n; i++) {
        int factor = (i - 1) * (mx[i] - mx[i - 1]) + mx[i] - list[i - 1];
        dp[i][0] = dp[i - 1][0] + factor;
        for (int j = 1; j < min(i, k + 1); j++) {
            int loc_max = 0, loc_cost = 0;
            dp[i][j] = INF;
            for (int l = i - 1; l >= 1; l--) {
                loc_cost += (i - l - 1) * (max(loc_max, list[l]) - loc_max) +
                            max(loc_max, list[l]) - list[l];
                loc_max = max(loc_max, list[l]);
                dp[i][j] = min(dp[l][j - 1] + loc_cost, dp[i][j]);
            }
        }
    }
    printf("%d", dp[n][k]);
}
