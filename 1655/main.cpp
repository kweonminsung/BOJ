#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int> pql;
priority_queue<int, vector<int>, greater<int>> pqr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;

    if (pql.empty()) {
      pql.push(input);
    } else if (pql.top() >= input) {
      pql.push(input);

      while (pql.size() - pqr.size() > 1) {
        pqr.push(pql.top());
        pql.pop();
      }
    } else {
      pqr.push(input);

      while (pql.size() < pqr.size()) {
        pql.push(pqr.top());
        pqr.pop();
      }
    }
    cout << pql.top() << "\n";
  }
}
