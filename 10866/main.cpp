#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  deque<int> D;

  while (n--) {
    string op;
    int num;
    cin >> op;

    if (op == "push_front") {
      cin >> num;
      D.push_front(num);
    } else if (op == "push_back") {
      cin >> num;
      D.push_back(num);
    } else if (op == "pop_front") {
      if (D.empty())
        cout << -1 << "\n";
      else {
        cout << D.front() << "\n";
        D.pop_front();
      }
    } else if (op == "pop_back") {
      if (D.empty())
        cout << -1 << "\n";
      else {
        cout << D.back() << "\n";
        D.pop_back();
      }
    } else if (op == "size") {
      cout << D.size() << "\n";
    } else if (op == "empty") {
      cout << (D.empty() ? 1 : 0) << "\n";
    } else if (op == "front") {
      if (D.empty())
        cout << -1 << "\n";
      else
        cout << D.front() << "\n";
    } else if (op == "back") {
      if (D.empty())
        cout << -1 << "\n";
      else
        cout << D.back() << "\n";
    }
  }
}
