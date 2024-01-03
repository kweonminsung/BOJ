#include <bits/stdc++.h>

using namespace std;

long long lcm(long long m, long long n)
{
  long long i = m;
  while (i % n != 0)
    i += m;
  return i;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a, b;
  cin >> a >> b;

  cout << lcm(a, b);
}
