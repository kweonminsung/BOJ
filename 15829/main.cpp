#include <bits/stdc++.h>

using namespace std;

long long M = 1234567891;
long long R = 31;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long l;
  string str;
  cin >> l >> str;
  long long result = 0;

  for (long long i = 0; i < l; i++) {
    long long r = 1;
    for (int j = 1; j <= i; j++) {

      r = (r * 31) % M;
    }
    result = (result + (long long)(str[i] - 'a' + 1) * r) % M;
  }
  cout << result;
}
