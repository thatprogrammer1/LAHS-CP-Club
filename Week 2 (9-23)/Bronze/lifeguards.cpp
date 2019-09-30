/*
USACO 2018 January - Bronze Problem 2: Lifeguards
Solution Explanation:

- store all the cow data and use the "mailbox" method of storing time data
- check how many times only 1 cow is there and store each time using the "mailbox" method
    - you can only lose total time slots in these time slots since the other time slots will have at least 1 backup
- for each cow and their time slots, check how many of the "one cow" slots they take up
    - the one that is there for the least amount of time (by themselves) can be discarded to maximize time slots taken up
- the result will be: (# slots filled by multiple) + [(# of slots filled by 1) - (cow that has the least spots to themselves)]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    if (fopen("lifeguards.in", "r")) {
        freopen("lifeguards.in", "r", stdin);
        freopen("lifeguards.out", "w", stdout);
    }

    int n;
    cin >> n;

    int time[1001] = {};

    int cows[100][2] = {};

    for (int i = 0; i < n; i++) { 
        int a, b;
        cin >> a >> b;
        cows[i][0] = a;
        cows[i][1] = b;
        for (int j = a; j < b; j++) {
            time[j] += 1;
        } 
    }

    int only[1001] = {};
    int multiCounter = 0;
    for (int i = 0; i < 1001; i++) {
        if (time[i] > 1) multiCounter += 1;
        if (time[i] == 1) only[i] = 1;
    }

    int minThere = 1000000; // way over the maximum possible value
    int totalThere = 0; // basically the amount of slots where only 1 cow is there

    for (int i = 0; i < 1001; i++) {
        if (only[i] == 1) totalThere += 1;
    }

    for (int i = 0; i < n; i++) {
        int there = 0;
        for (int j = cows[i][0]; j < cows[i][1]; j++) {
            if (only[j] == 1) there += 1;
        }
        minThere = min(minThere, there);
    }

    cout << multiCounter + (totalThere-minThere) << "\n";

    return 0;
}