/*

After analyzing the problem, it turns out that the optimal way to flip the board is the following:
- traverse from the bottom-right corner towards the top-left corner
- if the value is 1, flip the board in the way the problem states

If you do that process and keep track of how many times you flip, you will reach the answer.

*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("cowtip.in", "r")) {
        freopen("cowtip.in", "r", stdin);
        freopen("cowtip.out", "w", stdout);
    }

    int n;
    cin >> n;

    int board[20][20] = {0};
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            board[i][j] = line[j] - '0'; // convert char into int ('1' => 1 or '0' => 0)
        }
    }

    int numFlips = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--){
            if (board[i][j] == 1) {
                numFlips += 1;

                for (int a = 0; a <= i; a++) {
                    for (int b = 0; b <= j; b++) {
                        if (board[a][b] == 0) board[a][b] = 1;
                        else board[a][b] = 0;
                    }
                }



            }
        }
    }

    cout << numFlips << "\n";

    return 0;
}
