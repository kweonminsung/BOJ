#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 20;
  double total = 0, nums = 0;

  while (n--) {
    double num;
    string input, grade;
    cin;
    cin >> input >> num >> grade;

    if (grade == "P")
      continue;

    nums += num;

    if (grade == "A+")
      total += num * 4.5;
    else if (grade == "A0")
      total += num * 4.0;
    else if (grade == "B+")
      total += num * 3.5;
    else if (grade == "B0")
      total += num * 3.0;
    else if (grade == "C+")
      total += num * 2.5;
    else if (grade == "C0")
      total += num * 2.0;
    else if (grade == "D+")
      total += num * 1.5;
    else if (grade == "D0")
      total += num * 1.0;
  }

  cout << total / nums;
}
