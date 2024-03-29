#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  unordered_map<int, int> M;
  vector<int> V(N);
  for (int &v : V) {
    cin >> v;
    M[v]++;
  }

  stack<int> S;
  deque<int> result;
  for (int i = N - 1; i >= 0; i--) {
    while (!S.empty() && M[S.top()] <= M[V[i]])
      S.pop();

    if (S.empty()) {
      result.push_front(-1);
    } else {
      result.push_front(S.top());
    }
    S.push(V[i]);
  }

  for (int r : result)
    cout << r << " ";
}
