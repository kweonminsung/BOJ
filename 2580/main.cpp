#include <bits/stdc++.h>

using namespace std;

int board[9][9];
vector<pair<int, int>> spaces;

void func(int k) {
  if (k == spaces.size()) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++)
        cout << board[i][j] << " ";
      cout << "\n";
    }
    exit(0);
  }

  for (int i = 1; i <= 9; i++) {
    bool rowFlag = true, columnFlag = true, boxFlag = true;
    bool breakFlag = false;

    for (int j = 0; j < 9; j++)
      if (board[spaces[k].first][j] == i) {
        rowFlag = false;
        break;
      }
    if (!rowFlag)
      continue;

    for (int j = 0; j < 9; j++)
      if (board[j][spaces[k].second] == i) {
        columnFlag = false;
        breakFlag = true;
        break;
      }

    if (!columnFlag)
      continue;

    for (int j = (spaces[k].first / 3) * 3; j < (spaces[k].first / 3) * 3 + 3;
         j++) {
      for (int m = (spaces[k].second / 3) * 3;
           m < (spaces[k].second / 3) * 3 + 3; m++) {
        if (board[j][m] == i) {
          boxFlag = false;
          breakFlag = true;
          break;
        }
      }
      if (breakFlag)
        break;
    }
    if (!boxFlag)
      continue;

    board[spaces[k].first][spaces[k].second] = i;
    func(k + 1);
    board[spaces[k].first][spaces[k].second] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int input;
      cin >> input;
      board[i][j] = input;

      if (input == 0) {
        spaces.push_back({i, j});
      }
    }
  }

  func(0);
}
