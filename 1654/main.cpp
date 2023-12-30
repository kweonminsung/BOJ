#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long k, n;
  cin >> k >> n;
  vector<long> V;
  long maxN, result = 1;

  for (long i = 0; i < k; i++) {
    long input;
    cin >> input;
    V.push_back(input);
    maxN = max(maxN, input);
  }

  long left = 1, right = maxN, mid;

  while (left <= right) {
    mid = (left + right) / 2;

    long tot = 0;

    for (auto i : V) {
      tot += (i / mid);
    }

    if (tot >= n) {
      result = max(result, mid);

      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << result;
}
