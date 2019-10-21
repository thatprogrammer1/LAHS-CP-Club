/*
For this problem, it asks for any answer that works where when you select one 
number from A and one from B, the sum is not in A nor B. The easiest way to get a solution
is to get the highest value of A and the highest value of B since you are guarenteed that the
sum is not going to exist in A or B (since the values are all positive).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    int a[100];
    int b[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+m);

    cout << a[n-1] << " " << b[m-1] << "\n";

    return 0;
}