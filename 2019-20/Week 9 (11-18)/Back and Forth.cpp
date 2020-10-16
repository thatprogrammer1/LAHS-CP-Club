/*
For most bronze problems, a common strategy is to simulate the situation and try
all possible combinations. For this problem there are 10*11*11*11 combinations to
try, which is well under the limit of 2*10^6 operations. An easy approach is to define
a method for each day of the week and call the next day's method for each bucket that we
have on that day. Then on Friday, we record the solution. (Make sure to discard duplicate
solutions since it's just asking for the number of distinct solutions).
*/

#include <bits/stdc++.h>
using namespace std;

void wednesday(vector<int> A, vector<int> B, vector<int> curr);
void thursday(vector<int> A, vector<int> B, vector<int> curr);
void friday(vector<int> A, vector<int> B, vector<int> curr);

void tuesday(vector<int> A, vector<int> B, vector<int> curr) {
  for (int i = A.size() - 1; i >= 0; i--) {
    int c = A[i];
    B.push_back(A[i]);
    curr.push_back(A[i]);
    A.erase(A.begin() + i);
    
    wednesday(A, B, curr);

    curr.pop_back();
    B.pop_back();
    A.push_back(c);
  }
}

void wednesday(vector<int> A, vector<int> B, vector<int> curr) {
  for (int i = B.size() - 1; i >= 0; i--) {
    int c = B[i];
    A.push_back(B[i]);
    curr.push_back(B[i]);
    B.erase(B.begin() + i);
    
    thursday(A, B, curr);

    curr.pop_back();
    A.pop_back();
    B.push_back(c);
  }
}

void thursday(vector<int> A, vector<int> B, vector<int> curr) {
  for (int i = A.size() - 1; i >= 0; i--) {
    int c = A[i];
    B.push_back(A[i]);
    curr.push_back(A[i]);
    A.erase(A.begin() + i);
    
    friday(A, B, curr);

    curr.pop_back();
    B.pop_back();
    A.push_back(c);
  }
}

set<int> answers;

void friday(vector<int> A, vector<int> B, vector<int> curr) {
  for (int i = B.size() - 1; i >= 0; i--) {
    int c = B[i];
    A.push_back(B[i]);
    curr.push_back(B[i]);
    B.erase(B.begin() + i);

    int res = -curr[0] + curr[1] - curr[2] + curr[3];
    answers.insert(res);

    curr.pop_back();
    A.pop_back();
    B.push_back(c);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("backforth.in", "r")) {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
  }

  vector<int> A;
  vector<int> B;

  for (int i = 0; i < 10; i++) {
    int temp;
    cin >> temp;
    A.push_back(temp);
  }

  for (int i = 0; i < 10; i++) {
    int temp;
    cin >> temp;
    B.push_back(temp);
  }

  vector<int> c;
  tuesday(A, B, c);

  cout << answers.size() << "\n";

  return 0;
}