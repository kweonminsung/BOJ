#include <bits/stdc++.h>

using namespace std;

string arr[3];

void print(int n) {
  if (n % 5 == 0) {
    if (n % 3 == 0)
      cout << "FizzBuzz\n";
    else
      cout << "Buzz\n";
  } else if (n % 3 == 0)
    cout << "Fizz\n";
  else
    cout << n << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; i++) {
    cin >> arr[i];
    if (arr[i] != "Fizz" && arr[i] != "Buzz" && arr[i] != "FizzBuzz") {
      print(stoi(arr[i]) + 3 - i);
      break;
    }
  }
}
