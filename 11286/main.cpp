#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct cmp {
  bool operator()(ll a, ll b) {
    if (abs(a) == abs(b))
      return a > b;
    return abs(a) > abs(b);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  priority_queue<ll, vector<ll>, cmp> PQ;

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
