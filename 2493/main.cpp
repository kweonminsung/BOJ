#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  stack<pair<int, int>> S, St;

  for (int i = 1; i <= N; i++) {
    int input;
    cin >> input;

    if (S.empty()) {
      cout << "0 ";
    } else {
      while (true) {
        if (S.empty()) {
          cout << "0 ";
          break;
        }

        auto cur = S.top();
        if (cur.first >= input) {
          cout << cur.second << " ";
          break;
        }

        if (S.top().first > input)
          St.push(S.top());
        S.pop();
      }
      while (!St.empty()) {
        S.push(St.top());
        St.pop();
      }
    }
    S.push({input, i});
  }
}
