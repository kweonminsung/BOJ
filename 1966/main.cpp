#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n, m;
  cin >> t;

  while (t--) {
    cin >> n >> m;
    deque<int> Q, QO;
    for (int i = 0; i < n; i++) {
      int input;
      cin >> input;
      Q.push_back(input);
      QO.push_back(i);
    }

    int order = 1;
    while (true) {

      bool checkPrint = true;
      for (int i = 0; i < Q.size(); i++) {
        if (Q.front() < Q[i]) {
          checkPrint = false;
          break;
        }
      }

      if (checkPrint) {
        if (QO.front() == m) {
          cout << order << "\n";
          break;
        } else {
          Q.pop_front();
          QO.pop_front();

          order++;
        }
      } else {
        Q.push_back(Q.front());
        QO.push_back(QO.front());
        Q.pop_front();
        QO.pop_front();
      }
    }
  }
}
