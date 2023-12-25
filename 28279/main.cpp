#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  deque<int> D;

  while (N--) {
    int op;
    cin >> op;

    if (op == 1) {
      int add;
      cin >> add;
      D.push_front(add);
    } else if (op == 2) {
      int add;
      cin >> add;
      D.push_back(add);
    } else if (op == 3) {
      if (D.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << D.front() << "\n";
      D.pop_front();
    } else if (op == 4) {
      if (D.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << D.back() << "\n";
      D.pop_back();
    } else if (op == 5) {
      cout << D.size() << "\n";
    } else if (op == 6) {
      cout << (D.empty() ? 1 : 0) << "\n";
    } else if (op == 7) {
      if (D.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << D.front() << "\n";
    } else if (op == 8) {
      if (D.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << D.back() << "\n";
    }
  }
}
