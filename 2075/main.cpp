#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int input;
  for (int i = 0; i < n * n; i++) {
    cin >> input;

    if (pq.size() < n)
      pq.push(input);
    else if (pq.size() == n) {
      if (pq.top() < input) {
        pq.pop();
        pq.push(input);
      }
    }
  }

  cout << pq.top();
}
