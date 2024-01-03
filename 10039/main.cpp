#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tot = 0;

  for (int i = 0; i < 5; i++)
  {
    int n;
    cin >> n;

    if (n <= 40)
    {
      tot += 40;
      continue;
    }
    tot += n;
  }

  cout << tot / 5;
}
