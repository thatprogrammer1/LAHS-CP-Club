/*

The simplest way to solve this problem is to simulate it.
You can use an array to store the amount of milk in each bucket
and the maximum amount of milk for each bucket (2 arrays).

You can then use a for loop to simulate the milk pouring based
on the restrictions provided in the problem.
(You should have a variable to keep track of the state - i.e. which bucket
you are pouring out of or which you are pouring into. In this solution, the state
variable keeps track of which bucket I am pouring out of and uses that to figure
out which bucket I am pouring into.)

After simulating, you can print out the amount in each bucket.

*/

#include <bits/stdc++.h>
using namespace std;

int state = 0;
int cap[3];
int milk[3];

int main() {
    ios::sync_with_stdio(false);
    if (fopen("mixmilk.in", "r")) {
        freopen("mixmilk.in", "r", stdin);
        freopen("mixmilk.out", "w", stdout);
    }

    cin >> cap[0] >> milk[0];
    cin >> cap[1] >> milk[1];
    cin >> cap[2] >> milk[2];

    for (int i = 0; i < 100; i++) {
        int curr = state;
        int next = state+1;
        if (next == 3) next = 0;

        int spaceleft = cap[next] - milk[next];
        int amt = milk[curr];

        if (amt <= spaceleft) {
            milk[curr] -= amt;
            milk[next] += amt;
        } else if (amt > spaceleft) {
            milk[curr] -= spaceleft;
            milk[next] += spaceleft;
        }

        state += 1;
        if (state == 3) state = 0;
    }

    cout << milk[0] << "\n" << milk[1] << "\n" << milk[2] << "\n";

    return 0;
}