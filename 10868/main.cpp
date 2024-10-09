#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, M, a, b;
int arr[MAX], tree[4 * MAX];

int init(int start, int end, int n) {
  if (start == end) {
    return tree[n] = arr[start];
  }

  int mid = (start + end) / 2;
  return tree[n] = min(init(start, mid, 2 * n), init(mid + 1, end, 2 * n + 1));
}

int sum(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return INT_MAX;

  if (left <= start && end <= right)
    return tree[n];

  int mid = (start + end) / 2;
  return min(sum(start, mid, 2 * n, left, right),
             sum(mid + 1, end, 2 * n + 1, left, right));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  init(0, N - 1, 1);

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    cout << sum(0, N - 1, 1, a - 1, b - 1) << "\n";
  }
}
