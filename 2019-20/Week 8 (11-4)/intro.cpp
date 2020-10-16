#include <bits/stdc++.h>
using namespace std;
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
void flipCoins(bool curFlips[], int curCoin, int n) {
    // Given n coins, generate all possible sequences of heads and tails.
    if (curCoin == n) {
        string cur;
        for (int i = 0; i < n; i++) {
            cur += curFlips[i] ? "H" : "T";
        }
        cout << cur << endl;
        return;
    }
    curFlips[curCoin] = true;
    flipCoins(curFlips, curCoin + 1, n);
    curFlips[curCoin] = false;
    flipCoins(curFlips, curCoin + 1, n);
}
set<int> possValues;  // Use set to remove repeated values
void generateCoins(int coins[], bool used[], int curCoin, int n) {
    // Given n coins with values (a_1, a_2....a_n), generate all possible values
    // one can make.
    if (curCoin == n) {
        int curVal = 0;
        for (int i = 0; i < n; i++) {
            curVal += used[i] * coins[i];  // used[i] is 0 if false, 1 if true
        }
        possValues.insert(curVal);
        return;
    }
    used[curCoin] = true;
    generateCoins(coins, used, curCoin + 1, n);
    used[curCoin] = false;
    generateCoins(coins, used, curCoin + 1, n);
}
void generateKCoins(int coins[], bool used[], int curCoin, int n, int k) {
    // Given n coins with values (a_1, a_2....a_n), generate all possible values
    // one can make using EXACTLY k coins.
    if (curCoin == n + 1) {
        int curVal = 0;
        int usedCount = 0;
        for (int i = 0; i < n; i++) {
            usedCount += used[i];
            curVal += used[i] * coins[i];  // used[i] is 0 if false, 1 if true
        }
        if (usedCount == k) possValues.insert(curVal);
        return;
    }
    used[curCoin] = true;
    generateKCoins(coins, used, curCoin + 1, n, k);
    used[curCoin] = false;
    generateKCoins(coins, used, curCoin + 1, n, k);
}

void generateCoinsSum(int coins[], bool used[], int curCoin, int n, int sum) {
    // Given n coins with values (a_1, a_2....a_n), generate all possible
    // subsets (of the indices of the coins) that sum to a value of x.
    if (curCoin == n) {
        int curVal = 0;

        for (int i = 0; i < n; i++) {
            curVal += used[i] * coins[i];  // used[i] is 0 if false, 1 if true
        }
        if (curVal == sum) {
            for (int i = 0; i < n; i++) {
                if (used[i]) cout << (i + 1) << " ";
            }
            cout << endl;
        }

        return;
    }
    used[curCoin] = true;
    generateCoinsSum(coins, used, curCoin + 1, n, sum);
    used[curCoin] = false;
    generateCoinsSum(coins, used, curCoin + 1, n, sum);
}
int main() {
    ios::sync_with_stdio(false);
    if (fopen("input.in", "r")) {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    cout << factorial(4) << endl;
    bool curFlips[2] = {0};
    flipCoins(curFlips, 0, 3);
    int coins[3] = {1, 1, 2};
    generateCoins(coins, curFlips, 0, 3);
    cout << "Generating all possible values" << endl;
    for (auto i : possValues) cout << i << endl;
    possValues.clear();
    generateKCoins(coins, curFlips, 0, 3, 1);
    cout << "Generating all possible values with k coins" << endl;
    for (auto i : possValues) cout << i << endl;
    cout << "Generating indices to make x" << endl;
    generateCoinsSum(coins, curFlips, 0, 3, 2);
}