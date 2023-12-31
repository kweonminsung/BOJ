#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  bool S[21] = {0};

  while (n--) {
    string op;
    int input;
    cin >> op;

    if (op == "add") {
      cin >> input;

      S[input] = true;
    } else if (op == "remove") {
      cin >> input;

      S[input] = false;
    } else if (op == "check") {
      cin >> input;

      cout << (S[input] ? 1 : 0) << "\n";
    } else if (op == "toggle") {
      cin >> input;

      if (S[input])
        S[input] = false;
      else
        S[input] = true;
    } else if (op == "all") {
      for (int i = 1; i <= 20; i++)
        S[i] = true;
    } else if (op == "empty") {
      for (int i = 1; i <= 20; i++)
        S[i] = false;
    }
  }
}
