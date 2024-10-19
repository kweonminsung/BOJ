#include <bits/stdc++.h>

using namespace std;

int N, t;
vector<int> V;

void compress(vector<int> &A) {
  vector<int> B(A);
  sort(B.begin(), B.end());
  // Remove Duplicates
  B.erase(unique(B.begin(), B.end()), B.end());
  for (int &x : A)
    x = lower_bound(B.begin(), B.end(), x) - B.begin();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> t, V.push_back(t);

  compress(V);

  for (auto i : V)
    cout << i << " ";
}
