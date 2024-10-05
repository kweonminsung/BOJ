#include <bits/stdc++.h>
#define MAX 2000001

using namespace std;

int N, T, X;
int arr[MAX], tree[4 * MAX];

void insert(int start, int end, int n, int value) {
  if (value < start || value > end)
    return;

  tree[n]++;
  if (start == end)
    return;

  int mid = (start + end) / 2;
  insert(start, mid, 2 * n, value);
  insert(mid + 1, end, 2 * n + 1, value);
}

int find_(int start, int end, int n, int sum) {
  if (start == end) {
    tree[n]--;
    return start;
  }

  int mid = (start + end) / 2;
  int ret = 0;

  if (sum <= tree[2 * n])
    ret = find_(start, mid, 2 * n, sum);
  else
    ret = find_(mid + 1, end, 2 * n + 1, sum - tree[2 * n]);
  tree[n] = tree[2 * n] + tree[2 * n + 1];
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> T >> X;

    if (T == 1) {
      arr[X]++;
      insert(0, MAX - 1, 1, X);
    } else {
      cout << find_(0, MAX - 1, 1, X) << " \n";
    }
  }
}
