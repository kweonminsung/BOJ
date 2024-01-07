#include <bits/stdc++.h>

using namespace std;

queue<int> Q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    Q.push(i);
  }

  cout << "<";
  while (!Q.empty()) {
    int toPop = k % Q.size() == 0 ? k : k % Q.size();
    for (int i = 0; i < toPop - 1; i++) {
      Q.push(Q.front());
      Q.pop();
    }

    cout << Q.front();
    if (Q.size() == 1)
      cout << ">";
    else
      cout << ", ";
    Q.pop();
  }
}
