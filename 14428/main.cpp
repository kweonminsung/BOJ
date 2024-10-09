#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, M, a, b, c;
int arr[MAX], arrIndex[MAX];
pair<int, int> tree[4 * MAX];

inline pair<int, int> min(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first)
    return a.second < b.second ? a : b;
  return a.first < b.first ? a : b;
}

pair<int, int> init(int start, int end, int n) {
  if (start == end) {
    arrIndex[start] = n;
    return tree[n] = {arr[start], start};
  }

  int mid = (start + end) / 2;
  return tree[n] = min(init(start, mid, 2 * n), init(mid + 1, end, 2 * n + 1));
}

pair<int, int> sum(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return {INT_MAX, 0};

  if (left <= start && end <= right)
    return tree[n];

  int mid = (start + end) / 2;
  return min(sum(start, mid, 2 * n, left, right),
             sum(mid + 1, end, 2 * n + 1, left, right));
}

void update(int index, int value) {
  int cur = arrIndex[index];

  tree[cur] = {value, index};
  while (cur != 1) {
    tree[cur / 2] =
        min(tree[cur], tree[(cur % 2 == 0) ? (cur + 1) : (cur - 1)]);
    cur /= 2;
  }
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
    cin >> a >> b >> c;
    switch (a) {
    case 1:
      arr[b - 1] = c;
      update(b - 1, c);
      break;
    case 2:
      cout << sum(0, N - 1, 1, b - 1, c - 1).second + 1 << "\n";
      break;
    default:
      break;
    }
  }
}
