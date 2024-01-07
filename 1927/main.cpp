#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> V;

  for (int i = 0; i < n; i++)
  {
    int input;
    cin >> input;

    if (input == 0)
    {
      if (V.empty())
      {
        cout << "0\n";
        continue;
      }
      auto iter = min_element(V.begin(), V.end());
      cout << *iter << "\n";
      V.erase(iter);
      continue;
    }

    V.push_back(input);
  }
}
