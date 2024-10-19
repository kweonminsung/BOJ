#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int N, M;
int arr[MAX], tree[4 * MAX];

int init(int start, int end, int n) {
  if (start == end)
    return tree[n] = arr[start];

  int mid = (start + end) / 2;
  return tree[n] = max(init(start, mid, 2 * n), init(mid + 1, end, 2 * n + 1));
}

int query(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return 0;

  if (left <= start && end <= right)
    return tree[n];

  int mid = (start + end) / 2;
  return max(query(start, mid, 2 * n, left, right),
             query(mid + 1, end, 2 * n + 1, left, right));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> arr[i];
  init(0, N - 1, 1);

  for (int i = M - 1; i + M - 1 < N; i++)
    cout << query(0, N - 1, 1, i - M + 1, i + M - 1) << " ";
}
