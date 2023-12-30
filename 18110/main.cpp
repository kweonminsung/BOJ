#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> V;

  if (n == 0) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    V.push_back(input);
  }

  sort(V.begin(), V.end());

  int tot = 0, offset = round(double(n * 3) / 20);
  for (int i = offset; i + offset < n; i++) {
    tot += V[i];
  }

  cout << int(round(double(tot) / (n - offset * 2)));
}
