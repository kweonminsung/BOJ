#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  stack<int> S;
  vector<int> V;
  vector<char> result;
  int i, j = 0;

  for (i = 0; i < n; i++) {
    int input;
    cin >> input;
    V.push_back(input);
  }

  for (i = 1; i <= n;) {
    if (!S.empty() && S.top() == V[j]) {
      result.push_back('-');
      S.pop();
      j++;
    } else {
      result.push_back('+');
      S.push(i);
      i++;
    }
  }

  while (j < n) {
    if (S.top() == V[j]) {
      result.push_back('-');
      S.pop();
    } else {
      cout << "NO";
      return 0;
    }
    j++;
  }

  for (auto c : result)
    cout << c << "\n";
}
