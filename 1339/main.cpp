#include <bits/stdc++.h>

using namespace std;

int n, result = 0;
int alphaPivot[26];
vector<pair<char, int>> v;

bool cmp(pair<char, int> a, pair<char, int> b) { return a.second > b.second; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;

    for (int j = 0; j < input.size(); j++)
      alphaPivot[input[j] - 'A'] += int(pow(10, input.size() - 1 - j));
  }

  for (int i = 0; i < 26; i++) {
    if (alphaPivot[i] != 0) {
      v.push_back({i, alphaPivot[i]});
    }
  }
  sort(v.begin(), v.end(), cmp);

  for (int i = 9, j = 0; i >= 0 && j < v.size(); i--, j++) {
    result += v[j].second * i;
  }

  cout << result;
}
