#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a;
  cin >> a;

  if ((a <= 100) && (a >= 90))
    cout << "A";
  else if ((a <= 89) && (a >= 80))
    cout << "B";
  else if ((a <= 79) && (a >= 70))
    cout << "C";
  else if ((a <= 69) && (a >= 60))
    cout << "D";
  else
    cout << "F";
}
