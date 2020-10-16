/*

This problem has low constraints so it's easy to simulate the process.
To do so, create a large enough array, make the farmer start in the middle, and do each command.
	- the array should be initialized to numbers <= 0 so you know which parts of grass haven't been mowed
When going through each part of grass during each command, if the grass has already been mowed (aka. the value
of the array index is not the default), then find the time difference and compare that to the previously smallest difference.
If the patch of grass has not been mowed yet, then set that patch to the current time.

After the entire process, print out the smallest difference in time (or -1 if no patch was mowed multiple times).

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("mowing.in", "r")) {
        freopen("mowing.in", "r", stdin);
        freopen("mowing.out", "w", stdout);
    }

    int n;
    cin >> n;

    int board[2000][2000] = {{0}}; // more than big enough
    int x = 1000;
    int y = 1000;

    int time = 0;

    int minDiff = 10000000;

    for (int i = 0; i < n; i++) {
        char dir;
        int steps;
        cin >> dir >> steps;

        for (int j = 1; j <= steps; j++) {
            time += 1;
            if (dir == 'N') y -= 1;
            if (dir == 'S') y += 1;
            if (dir == 'W') x -= 1;
            if (dir == 'E') x += 1;

            if (board[x][y] != 0) { // already mowed before
                minDiff = min(minDiff, time-board[x][y]);
                board[x][y] = time;
            } else {
                board[x][y] = time;
            }
        }
    }

    if (minDiff == 10000000) minDiff = -1;

    cout << minDiff << "\n";

    return 0;
}