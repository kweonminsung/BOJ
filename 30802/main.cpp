#include <bits/stdc++.h>

using namespace std;

int N, T, P, cnt = 0;
int arr[6];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < 6; i++)
    cin >> arr[i];
  cin >> T >> P;

  for (int i = 0; i < 6; i++)
    cnt += (arr[i] % T == 0) ? arr[i] / T : arr[i] / T + 1;

  cout << cnt << "\n" << N / P << " " << N % P;
}
