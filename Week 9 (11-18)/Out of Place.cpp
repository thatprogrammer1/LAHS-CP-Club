/*
This problem can be solved using the observation that if we have
X amount of cows who are out of place (i.e. they are not in the same position
as the sorted array of cows), then we can arrange them in the correct position
in X-1 swaps. The only exception to this is that if we have 0 cows out of position
since that would require 0 swaps.
*/
#include <bits/stdc++.h>
using namespace std;

#define N 100

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("outofplace.in", "r")) {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
  }

  int n, h[N], sorted[N];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    sorted[i] = h[i];
  }
  sort(sorted, sorted+n);

  int wrong = 0;
  for (int i = 0; i < n; i++) {
    if (h[i] != sorted[i]) wrong++;
  }
  int ans = 0;
  if (wrong == 0) ans = 0;
  if (wrong > 0) ans = wrong-1;

  cout << ans << "\n";
  return 0;
}