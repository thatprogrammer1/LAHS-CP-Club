#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1000000];
int main() {
    ios::sync_with_stdio(false);
    if (fopen("input.in", "r")) {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}
