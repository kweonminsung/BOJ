#include <bits/stdc++.h>

using namespace std;

string str;
bool broken = false;
stack<int> S;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;

  for (char c : str) {
    if (c == '(' || c == '[')
      S.push(c);
    else if (c == ')') {
      if (S.empty() || S.top() != '(') {
        broken = true;
        break;
      }
      S.pop();
    } else {
      if (S.empty() || S.top() != '[') {
        broken = true;
        break;
      }
      S.pop();
    }
  }

  if (broken || !S.empty()) {
    cout << "0";
    return 0;
  }

  for (char c : str) {
    if (c == '(' || c == '[')
      S.push(c);
    else if (c == ')') {
      int temp = 0;
      while (S.top() != '(') {
        temp += S.top();
        S.pop();
      }

      S.pop();
      if (temp == 0)
        S.push(2);
      else
        S.push(2 * temp);
    } else {
      int temp = 0;
      while (S.top() != '[') {
        temp += S.top();
        S.pop();
      }

      S.pop();
      if (temp == 0)
        S.push(3);
      else
        S.push(3 * temp);
    }
  }

  int total = 0;
  while (!S.empty()) {
    total += S.top();
    S.pop();
  }
  cout << total;
}
