#include <bits/stdc++.h>

using namespace std;

bool checkPrime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

long long calc(long long n) {
  if (n == 1 || n == 0)
    return 2;

  for (long long i = n;; i++) {
    if (checkPrime(i))
      return i;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long n;
  cin >> n;

  for (long long i = 0; i < n; i++) {
    long long input;
    cin >> input;
    cout << calc(input) << "\n";
  }
}
