#include <bits/stdc++.h>

using namespace std;

vector<int> gaps;

int gcd() {
  for (int i = *min_element(gaps.begin(), gaps.end()); i >= 1; i--) {
    bool flag = true;
    for (auto g : gaps) {
      if (g % i != 0) {
        flag = false;
        break;
      }
    }

    if (flag)
      return i;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;

  int n, before;
  cin >> n;

  cin >> before;
  for (int i = 0; i < n - 1; i++) {
    int input;
    cin >> input;

    int gap = input - before;
    gaps.push_back(gap);
    before = input;
  }

  int G = gcd();

  for (auto i : gaps) {
    cnt += i / G - 1;
  }

  cout << cnt;
}
