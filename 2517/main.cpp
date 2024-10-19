#include <bits/stdc++.h>
#define MAX 500001

using namespace std;

int N, t;
vector<int> V;
int arrIndex[MAX], tree[4 * MAX];

void compress(vector<int> &A) {
  vector<int> B(A);
  sort(B.begin(), B.end());
  for (int &x : A)
    x = lower_bound(B.begin(), B.end(), x) - B.begin();
}

void init(int start, int end, int n) {
  if (start == end) {
    arrIndex[start] = n;
    return;
  }

  int mid = (start + end) / 2;
  init(start, mid, 2 * n);
  init(mid + 1, end, 2 * n + 1);
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

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> t;
    V.push_back(t);
  }
  compress(V);

  init(0, N - 1, 1);

  for (int i = 0; i < N; i++) {
    update(V[i], 1);
    cout << i - query(0, N - 1, 1, 0, V[i] - 1) + 1 << "\n";
  }
}
