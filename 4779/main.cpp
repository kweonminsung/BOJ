#include <bits/stdc++.h>

using namespace std;

bool check(int x, int n) {
  if (x < 3) {
    if (x == 1)
      return false;
    return true;
  }

  if (x / n == 1)
    return false;

  return check(x % n, n / 3);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  int n;
  while (1) {
    getline(cin, str);
    n = atoi(str.c_str());

    if (cin.eof())
      break;

    for (int i = 0; i < pow(3, n); i++) {
      cout << (check(i, pow(3, n)) ? "-" : " ");
    }
    cout << "\n";
  }
}