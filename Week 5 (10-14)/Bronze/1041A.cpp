/*
After playing around with the problem, you should realize that the optimal 
x value (the starting index of the IDs) should be the lowest ID. This ensures 
that all IDs given are possible and that the lowest number of laptops were stolen.
In order to solve the problem using this knowledge, you can sort the array of IDs and
add the differences between the elements in the sorted array (remember to subtract 1 from each
difference since you're looking for the amount above 1--which is the normal value). For example, if 
two elements are [10, 11], the difference should be 0 since no laptop was stolen in between those two IDs.
However, if the elements are [11, 13], the difference should be 1 since 1 laptop was stolen in between
those two IDs.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += a[i] - a[i-1] - 1;
    }

    cout << ans << "\n";

    return 0;
}