#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> PQ;

  for (int i = 0; i < n; i++) {
    ll input;
    cin >> input;

    if (input == 0) {
      if (PQ.empty()) {
        cout << "0\n";
        continue;
      }

      cout << PQ.top() << "\n";
      PQ.pop();
      continue;
    }

    PQ.push(input);
  }
}
