#include <bits/stdc++.h>

using namespace std;

long n, m;
long minN, tot;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  tot = 0;
  minN = 1000000000;

  for(long i = 0; i < n; i++) {
    for(long j = 0; j < m; j++) {
      long tmp;
      cin >> tmp;
      minN = min(minN, tmp);
      tot += tmp;
    }
  }

  cout << (tot - minN);
}