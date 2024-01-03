#include <bits/stdc++.h>

using namespace std;

int lcm(int m, int n)
{
  int i = m;
  while (i % n != 0)
    i += m;
  return i;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  long long a, b;

  while (n--)
  {
    cin >> a >> b;
    cout << lcm(a, b) << "\n";
  }
}
