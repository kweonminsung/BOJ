#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n, input, cnt = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    pq.push(input);
  }

  while (pq.size() != 1) {
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();

    pq.push(first + second);
    cnt += first + second;
  }

  cout << cnt;
}
