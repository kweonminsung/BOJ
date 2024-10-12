#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int n, a, b, c;
int arr[MAX + 1], arrIndex[MAX + 1], tree[4 * (MAX + 1)];

void init(int start, int end, int n) {
  if (start == end) {
    arrIndex[start] = n;
    return;
  }

  int mid = (start + end) / 2;
  init(start, mid, 2 * n);
  init(mid + 1, end, 2 * n + 1);
}

void update(int index, int diff) {
  int cur = arrIndex[index];

  tree[cur] += diff;
  while (cur != 1) {
    tree[cur / 2] = tree[cur] + tree[(cur % 2 == 0) ? (cur + 1) : (cur - 1)];
    cur /= 2;
  }
}

int query(int start, int end, int n, int sum) {
  if (start == end) {
    tree[n]--;
    return start;
  }

  int mid = (start + end) / 2;
  int ret = 0;

  if (sum <= tree[2 * n])
    ret = query(start, mid, 2 * n, sum);
  else
    ret = query(mid + 1, end, 2 * n + 1, sum - tree[2 * n]);
  tree[n] = tree[2 * n] + tree[2 * n + 1];
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  init(0, MAX - 1, 1);

  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b;
      cout << query(0, MAX - 1, 1, b) + 1 << "\n";
    } else {
      cin >> b >> c;
      update(b - 1, c);
    }
  }
}
