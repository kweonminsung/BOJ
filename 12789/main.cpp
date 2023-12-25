#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;
  int index = 1;

  stack<int> S;

  while (q--) {
    int num;
    cin >> num;

    if (index == num) {
      index++;
      continue;
    }
    while (!S.empty() && S.top() == index) {
      index++;
      S.pop();
    }
    S.push(num);
  }

  while (!S.empty() && S.top() == index) {
    index++;
    S.pop();
  }

  cout << (S.empty() ? "Nice" : "Sad");
}
