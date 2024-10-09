#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, M, a, b, c, input;
vector<int> tree[4 * MAX];

void update(int start, int end, int n, int index, int value) {
  if (!(start <= index && index <= end))
    return;

  tree[n].push_back(value);

  if (start != end) {
    int mid = (start + end) / 2;
    update(start, mid, 2 * n, index, value);
    update(mid + 1, end, 2 * n + 1, index, value);
  }
}

int query(int start, int end, int n, int value, int left, int right) {
  if (left > end || right < start)
    return 0;

  if (left <= start && end <= right)
    return tree[n].end() - upper_bound(tree[n].begin(), tree[n].end(), value);
  else {
    int mid = (start + end) / 2;
    return query(start, mid, 2 * n, value, left, right) +
           query(mid + 1, end, 2 * n + 1, value, left, right);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> input;
    update(0, N - 1, 1, i, input);
  }
  for (int i = 1; i < 4 * N; i++)
    sort(tree[i].begin(), tree[i].end());

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    cout << query(0, N - 1, 1, c, a - 1, b - 1) << "\n";
  }
}
