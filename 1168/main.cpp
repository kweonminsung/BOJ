#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, K, n, last;
int arr[MAX], tree[4 * MAX];
vector<int> V;

int init(int start, int end, int n) {
  if (start == end) {
    return tree[n] = arr[start];
  }

  int mid = (start + end) / 2;
  return tree[n] = init(start, mid, 2 * n) + init(mid + 1, end, 2 * n + 1);
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

int sum(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return 0;

  if (left <= start && end <= right)
    return tree[n];

  int mid = (start + end) / 2;
  return sum(start, mid, 2 * n, left, right) +
         sum(mid + 1, end, 2 * n + 1, left, right);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  n = N;

  for (int i = 0; i < N; i++)
    arr[i]++;
  init(0, N - 1, 1);

  last = find_(0, N - 1, 1, K) + 1;
  cout << "<" << last;
  n--;

  while (n != 0) {
    int cnt = (sum(0, N - 1, 1, 0, last - 1) + K) % n;
    cnt = (cnt == 0 ? n : cnt);

    V.push_back(cnt);
    last = find_(0, N - 1, 1, cnt) + 1;
    cout << ", " << last;
    n--;
  }
  cout << ">";
}
