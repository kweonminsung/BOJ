#include <bits/stdc++.h>
#define MAX 200001

using namespace std;

int T, n, m, k, tmpM;
int arrIndex[MAX], tree[4 * MAX], arrLoc[MAX];

int init(int start, int end, int n) {
  if (start == end) {
    if (tmpM > 0) {
      arrIndex[start] = n;
      tmpM--;
      return 0;
    }
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

int query(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return 0;

  if (left <= start && end <= right)
    return tree[n];

  int mid = (start + end) / 2;
  return query(start, mid, 2 * n, left, right) +
         query(mid + 1, end, 2 * n + 1, left, right);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> n >> m;
    fill(tree, tree + 4 * (n + m), 0);

    tmpM = m;
    init(0, m + n - 1, 1);
    for (int j = 0; j < n; j++)
      arrLoc[j] = m + j;

    tmpM = m;
    for (int j = 0; j < m; j++) {
      cin >> k;
      cout << query(0, m + n - 1, 1, 0, arrLoc[k - 1]) - 1 << " ";
      update(arrLoc[k - 1], 0);
      update(tmpM - 1, 1);
      arrLoc[k - 1] = tmpM - 1;
      tmpM--;
    }
    cout << "\n";
  }
}