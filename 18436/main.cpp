#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, M, a, b, c;
int arr[MAX], arrIndex[MAX], oddTree[4 * MAX], evenTree[4 * MAX];

int initOdd(int start, int end, int n) {
  if (start == end) {
    arrIndex[start] = n;
    return oddTree[n] = (arr[start] % 2 == 1) ? 1 : 0;
  }

  int mid = (start + end) / 2;
  return oddTree[n] =
             initOdd(start, mid, 2 * n) + initOdd(mid + 1, end, 2 * n + 1);
}

int initEven(int start, int end, int n) {
  if (start == end) {
    return evenTree[n] = (arr[start] % 2 == 0) ? 1 : 0;
  }

  int mid = (start + end) / 2;
  return evenTree[n] =
             initEven(start, mid, 2 * n) + initEven(mid + 1, end, 2 * n + 1);
}

int sumOdd(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return 0;

  if (left <= start && end <= right)
    return oddTree[n];

  int mid = (start + end) / 2;
  return sumOdd(start, mid, 2 * n, left, right) +
         sumOdd(mid + 1, end, 2 * n + 1, left, right);
}

int sumEven(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return 0;

  if (left <= start && end <= right)
    return evenTree[n];

  int mid = (start + end) / 2;
  return sumEven(start, mid, 2 * n, left, right) +
         sumEven(mid + 1, end, 2 * n + 1, left, right);
}

void update(int index, int value) {
  int cur = arrIndex[index];

  oddTree[cur] = (value % 2 == 1) ? 1 : 0;
  evenTree[cur] = (value % 2 == 0) ? 1 : 0;
  while (cur != 1) {
    oddTree[cur / 2] =
        oddTree[cur] + oddTree[(cur % 2 == 0) ? (cur + 1) : (cur - 1)];
    evenTree[cur / 2] =
        evenTree[cur] + evenTree[(cur % 2 == 0) ? (cur + 1) : (cur - 1)];
    cur /= 2;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  initOdd(0, N - 1, 1);
  initEven(0, N - 1, 1);

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    switch (a) {
    case 1:
      arr[b - 1] = c;
      update(b - 1, c);
      break;
    case 2:
      cout << sumEven(0, N - 1, 1, b - 1, c - 1) << "\n";
      break;
    case 3:
      cout << sumOdd(0, N - 1, 1, b - 1, c - 1) << "\n";
      break;
    default:
      break;
    }
  }
}
