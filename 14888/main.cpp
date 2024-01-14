#include <bits/stdc++.h>

using namespace std;

int n;

int nums[12];
int resultN[12];
int ops[4]; // + - * /
int maxN = INT_MIN, minN = INT_MAX;

void func(int k) {
  if (k == n) {
    maxN = max(resultN[n - 1], maxN);
    minN = min(resultN[n - 1], minN);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (ops[i] == 0)
      continue;

    ops[i]--;
    switch (i) {
    case 0:
      resultN[k] = resultN[k - 1] + nums[k];
      break;
    case 1:
      resultN[k] = resultN[k - 1] - nums[k];
      break;
    case 2:
      resultN[k] = resultN[k - 1] * nums[k];
      break;
    case 3:
      resultN[k] = resultN[k - 1] / nums[k];
      break;
    }
    func(k + 1);
    ops[i]++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  resultN[0] = nums[0];

  for (int i = 0; i < 4; i++)
    cin >> ops[i];

  func(1);

  cout << maxN << "\n" << minN;
}
