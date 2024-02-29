#include <bits/stdc++.h>

using namespace std;

int l, c;
char input[16];
char arr[16];
bool used[16];

bool consonantCheck(char f) {
  if (f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u')
    return true;
  return false;
}

void func(int k, int m, int n) {
  if (k == l) {
    if (n < 1 || l - n < 2)
      return;

    for (int i = 0; i < l; i++) {
      cout << arr[i];
    }
    cout << "\n";
    return;
  }

  for (int i = m; i < c; i++) {
    if (used[i])
      continue;

    arr[k] = input[i];
    used[i] = true;
    func(k + 1, i + 1, consonantCheck(arr[k]) ? n + 1 : n);
    used[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> c;

  for (int i = 0; i < c; i++) {
    cin >> input[i];
  }

  sort(input, input + c);

  func(0, 0, 0);
}
