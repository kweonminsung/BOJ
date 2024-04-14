#include <bits/stdc++.h>

using namespace std;
bool apple[100][100];
bool snakeBoard[100][100];

queue<pair<int, char>> dirChange;
deque<pair<int, int>> snake;

int n, k, l;
int x, y, t = 0;
char d;
pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dir = 1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    apple[x - 1][y - 1] = true;
  }

  cin >> l;
  for (int i = 0; i < l; i++) {
    cin >> x >> d;
    dirChange.push({x, d});
  }

  snake.push_front({0, 0});
  snakeBoard[0][0] = true;

  while (true) {
    snake.push_front({snake.front().first + dirs[dir].first,
                      snake.front().second + dirs[dir].second});
    auto sFront = snake.front();
    auto sBack = snake.back();

    if (snakeBoard[sFront.first][sFront.second] || sFront.first < 0 ||
        sFront.first >= n || sFront.second < 0 || sFront.second >= n)
      break;

    snakeBoard[sFront.first][sFront.second] = true;

    if (apple[sFront.first][sFront.second]) {
      apple[sFront.first][sFront.second] = false;
    } else {
      snakeBoard[sBack.first][sBack.second] = false;
      snake.pop_back();
    }

    t++;

    if (!dirChange.empty() && dirChange.front().first == t) {
      if (dirChange.front().second == 'D') {
        dir = (dir + 1) % 4;
      } else {
        dir = (dir + 3) % 4;
      }
      dirChange.pop();
    }
  }

  cout << t + 1;
}
