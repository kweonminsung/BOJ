#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;
using ll = long long;

int N, M, a, b, c, d, q1N = 0, q2N = 0;
ll arr[MAX], arrIndex[MAX], tree[4 * MAX], result[MAX];
vector<array<int, 2>> q1;
vector<array<int, 4>> q2;

ll init(int start, int end, int n) {
  if (start == end) {
    arrIndex[start] = n;
    return tree[n] = arr[start];
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

ll query(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return 0;

  if (left <= start && end <= right)
    return tree[n];

  int mid = (start + end) / 2;
  return query(start, mid, 2 * n, left, right) +
         query(mid + 1, end, 2 * n + 1, left, right);
}

bool cmp(array<int, 4> a, array<int, 4> b) {
  if (a[0] == b[0])
    return a[3] < b[3];
  return a[0] < b[0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  init(0, N - 1, 1);

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
      q1.push_back({b, c});
      q1N++;
    } else {
      cin >> b >> c >> d;
      q2.push_back({b, c, d, q2N});
      q2N++;
    }
  }

  sort(q2.begin(), q2.end(), cmp);

  int t = 0;
  for (int i = 0; i <= q1N; i++) {
    if (i > 0)
      update(q1[i - 1][0] - 1, q1[i - 1][1]);

    while (t <= q2N && q2[t][0] == i) {
      result[q2[t][3]] = query(0, N - 1, 1, q2[t][1] - 1, q2[t][2] - 1);
      t++;
    }
  }

  for (int i = 0; i < q2N; i++)
    cout << result[i] << "\n";
}
