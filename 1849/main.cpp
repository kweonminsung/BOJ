#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, t;
int arr[MAX], arrIndex[MAX], tree[4 * MAX];

int init(int start, int end, int n) {
  if (start == end) {
    arrIndex[start] = n;
    return tree[n] = 1;
  }

  int mid = (start + end) / 2;
  return tree[n] = init(start, mid, 2 * n) + init(mid + 1, end, 2 * n + 1);
}

void update(int index, int value) {
  int cur = arrIndex[index];

  tree[cur] = value;
  while (cur != 1) {
    tree[cur / 2] = tree[cur] + tree[(cur % 2 == 0) ? (cur + 1) : (cur - 1)];
    cur /= 2;
  }
}

int query(int start, int end, int n, int sum) {
  if (start == end)
    return start;

  int mid = (start + end) / 2;
  int ret = 0;

  if (sum <= tree[2 * n])
    ret = query(start, mid, 2 * n, sum);
  else
    ret = query(mid + 1, end, 2 * n + 1, sum - tree[2 * n]);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  fill(tree, tree + 4 * N, 1);
  init(0, N - 1, 1);

  for (int i = 0; i < N; i++) {
    cin >> t;
    int tmp = query(0, N - 1, 1, t + 1);
    update(tmp, 0);
    arr[tmp] = i;
  }
  for (int i = 0; i < N; i++)
    cout << arr[i] + 1 << "\n";
}
