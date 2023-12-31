#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string init;
  cin >> init;
  list<char> L;
  for (auto c : init)
    L.push_back(c);
  auto cursor = L.end();

  int q;
  cin >> q;

  while (q--) {
    char op;
    cin >> op;

    switch (op) {
    case 'L':
      if (cursor != L.begin())
        cursor--;
      break;
    case 'D':
      if (cursor != L.end())
        cursor++;
      break;
    case 'B':
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
      break;
    case 'P':
      char add;
      cin >> add;
      L.insert(cursor, add);
      break;
    }
  }
  for (auto c : L)
    cout << c;
}
