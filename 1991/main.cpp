#include <bits/stdc++.h>

using namespace std;

int N;
int L[26];
int R[26];

void rdfs(int k) {
  cout << char(k + 'A');
  if (L[k] != 0)
    rdfs(L[k]);
  if (R[k] != 0)
    rdfs(R[k]);
}

void mdfs(int k) {
  if (L[k] != 0)
    mdfs(L[k]);
  cout << char(k + 'A');
  if (R[k] != 0)
    mdfs(R[k]);
}

void edfs(int k) {
  if (L[k] != 0)
    edfs(L[k]);
  if (R[k] != 0)
    edfs(R[k]);
  cout << char(k + 'A');
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    char n, l, r;
    cin >> n >> l >> r;
    if (l != '.')
      L[n - 'A'] = l - 'A';
    if (r != '.')
      R[n - 'A'] = r - 'A';
  }

  rdfs(0);
  cout << "\n";
  mdfs(0);
  cout << "\n";
  edfs(0);
}
