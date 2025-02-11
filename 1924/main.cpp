#include <bits/stdc++.h>

using namespace std;

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int weekDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m, n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;

  int ans = 0;
  for (int i = 1; i < m; i++)
    ans += weekDays[i];

  cout << week[(ans + n - 1) % 7];
}
