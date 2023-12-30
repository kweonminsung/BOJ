#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  stack<int> S;

  while (n--) {
    string op;
    int num;
    cin >> op;

    if (op == "push") {
      cin >> num;
      S.push(num);
    } else if (op == "pop") {
      if (S.empty())
        cout << -1 << "\n";
      else {
        cout << S.top() << "\n";
        S.pop();
      }
    } else if (op == "size") {
      cout << S.size() << "\n";
    } else if (op == "empty") {
      cout << (S.empty() ? 1 : 0) << "\n";
    } else if (op == "top") {
      if (S.empty())
        cout << -1 << "\n";
      else
        cout << S.top() << "\n";
    }
  }
}
