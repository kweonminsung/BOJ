#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  long long result = 0;
  stack<int> S;

  for (int i = 1; i <= N; i++) {
    int input;
    cin >> input;

    if (S.empty()) {
      S.push(input);
      continue;
    }

    while (!S.empty() && S.top() <= input)
      S.pop();

    result += S.size();

    S.push(input);
  }

  cout << result;
}
