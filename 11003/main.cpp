#include <bits/stdc++.h>

using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

int n, l;
int arr[5000000];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int input, tempF;
  for (int i = 0; i < n; i++) {
    input = arr[i];

    pq.push({i, input});

    while (pq.top().first < i - l + 1)
      pq.pop();

    cout << pq.top().second << " ";
  }
}
