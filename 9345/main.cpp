#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int T, N, K, Q, A, B;
int arr[MAX], arrIndex[MAX], maxTree[4 * MAX], minTree[4 * MAX];

int initMax(int start, int end, int n) {
  if (start == end) {
    arrIndex[start] = n;
    return maxTree[n] = arr[start];
  }

  int mid = (start + end) / 2;
  return maxTree[n] =
             max(initMax(start, mid, 2 * n), initMax(mid + 1, end, 2 * n + 1));
}

void update(int index, int value) {
  int n = arrIndex[index];

  maxTree[n] = value;
  minTree[n] = value;

  while (n != 1) {
    maxTree[n / 2] = max(maxTree[n], maxTree[(n % 2 == 0) ? (n + 1) : (n - 1)]);
    minTree[n / 2] = min(minTree[n], minTree[(n % 2 == 0) ? (n + 1) : (n - 1)]);
    n /= 2;
  }
}

int getMax(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return INT_MIN;
  if (left <= start && end <= right)
    return maxTree[n];

  int mid = (start + end) / 2;
  return max(getMax(start, mid, 2 * n, left, right),
             getMax(mid + 1, end, 2 * n + 1, left, right));
}

int initMin(int start, int end, int n) {
  if (start == end) {
    return minTree[n] = arr[start];
  }

  int mid = (start + end) / 2;
  return minTree[n] =
             min(initMin(start, mid, 2 * n), initMin(mid + 1, end, 2 * n + 1));
}

int getMin(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return INT_MAX;
  if (left <= start && end <= right)
    return minTree[n];

  int mid = (start + end) / 2;
  return min(getMin(start, mid, 2 * n, left, right),
             getMin(mid + 1, end, 2 * n + 1, left, right));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N >> K;

    for (int m = 0; m < N; m++)
      arr[m] = m;
    fill(arrIndex, arrIndex + N, 0);
    fill(maxTree, maxTree + 4 * N, 0);
    fill(minTree, minTree + 4 * N, 0);

    initMax(0, N - 1, 1);
    initMin(0, N - 1, 1);

    for (int j = 0; j < K; j++) {
      cin >> Q >> A >> B;

      if (Q == 0) {
        update(A, arr[B]);
        update(B, arr[A]);

        int tmp = arr[B];
        arr[B] = arr[A];
        arr[A] = tmp;
      } else {
        cout << (((getMin(0, N - 1, 1, A, B) == A) &&
                  (getMax(0, N - 1, 1, A, B) == B))
                     ? "YES"
                     : "NO")
             << "\n";
      }
    }
  }
}
