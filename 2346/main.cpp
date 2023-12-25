#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  deque<pair<int, int>> D;

  for (int i = 1; i <= N; i++) {
    int add;
    cin >> add;
    D.push_back({i, add});
  }

  while (!D.empty()) {
    auto popped = D.front();
    cout << popped.first << " ";
    D.pop_front();

    if (popped.second > 0) {
      for (int i = 1; i < popped.second; i++) {
        D.push_back(D.front());
        D.pop_front();
      }
    } else if (popped.second < 0) {
      for (int i = 0; i > popped.second; i--) {
        D.push_front(D.back());
        D.pop_back();
      }
    }
  }
}
