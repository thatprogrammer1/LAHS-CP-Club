/*
The steps taken to solve the problem are as follows:
- create a hashmap to store the milk output of each cow
- loop through the input and update the milk output to the respective cow
- find the minimum (we need the minimum to figure out the second to last value/cow(s))
- using the minimum, find the second to last cow(s)
  - similar to finding the minimum except you also want to make sure that the value isn't equal to the minimum
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("notlast.in", "r")) {
        freopen("notlast.in", "r", stdin);
        freopen("notlast.out", "w", stdout);
    }

    int n;
    cin >> n;

    unordered_map<string, int> data = {
        {"Bessie", 0},
        {"Elsie", 0},
        {"Daisy", 0},
        {"Gertie", 0},
        {"Annabelle", 0},
        {"Maggie", 0},
        {"Henrietta", 0}
    };
    //Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta
    for (int i = 0; i < n; i++) {
        string name;
        int change;
        cin >> name >> change;
        data[name] += change;
    }

    int m = 1000000000;
    for (auto el : data) {
        m = min(m, el.second);
    }

    int low = 1000000000;
    vector<string> names;
    for (auto el : data) {
        if (el.second < low && el.second > m) {
            names.clear();
            names.push_back(el.first);
            low = el.second;
        }
        else if (el.second == low) {
            names.push_back(el.first);
        }
    }

    if (names.size() > 1 || names.size() == 0) {
        cout << "Tie\n";
    } else {
        cout << names[0] << "\n";
    }

    return 0;
}