#include <bits/stdc++.h>
#include <climits>
#define MAX 100001

using namespace std;
using ll = long long;

int N, M;
ll a, b;
ll arr[MAX], maxTree[4 * MAX], minTree[4 * MAX];

ll maxInit(int start, int end, int n) {
  if (start == end)
    return maxTree[n] = arr[start];

  int mid = (start + end) / 2;
  return maxTree[n] =
             max(maxInit(start, mid, 2 * n), maxInit(mid + 1, end, 2 * n + 1));
}

ll getMax(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return LONG_LONG_MIN;
  if (left <= start && end <= right)
    return maxTree[n];

  int mid = (start + end) / 2;
  return max(getMax(start, mid, 2 * n, left, right),
             getMax(mid + 1, end, 2 * n + 1, left, right));
}

ll minInit(int start, int end, int n) {
  if (start == end)
    return minTree[n] = arr[start];

  int mid = (start + end) / 2;
  return minTree[n] =
             min(minInit(start, mid, 2 * n), minInit(mid + 1, end, 2 * n + 1));
}

ll getMin(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return LONG_LONG_MAX;
  if (left <= start && end <= right)
    return minTree[n];

  int mid = (start + end) / 2;
  return min(getMin(start, mid, 2 * n, left, right),
             getMin(mid + 1, end, 2 * n + 1, left, right));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  maxInit(0, N - 1, 1);
  minInit(0, N - 1, 1);

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    cout << getMin(0, N - 1, 1, a - 1, b - 1) << " "
         << getMax(0, N - 1, 1, a - 1, b - 1) << "\n";
  }
}
