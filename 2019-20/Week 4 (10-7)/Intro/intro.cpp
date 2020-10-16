#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    if (fopen("input.in", "r")) {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == 1)
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%d\n", lo);
}
