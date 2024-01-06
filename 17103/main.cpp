#include <bits/stdc++.h>

using namespace std;

vector<bool> isPrime(1000001, true);

void SetPrime() {
  for (int i = 2; i * i <= 1000000; i++) {
    if (!isPrime[i])
      continue;

    for (int j = i * i; j <= 1000000; j += i)
      isPrime[j] = false;
  }
}

int main() {
  SetPrime();
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int cnt = 0, input;
    cin >> input;
    vector<int> v;

    for (int i = 2; i < input; i++) {
      if (isPrime[i])
        v.push_back(i);
    }

    for (auto it = v.begin(); it != v.end(); it++) {
      int other = input - *it;

      if (other < *it)
        break;

      if (binary_search(it, v.end(), other))
        cnt++;
    }

    cout << cnt << '\n';
  }
}