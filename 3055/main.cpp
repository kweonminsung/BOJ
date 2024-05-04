#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int R, C;
string board[51];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int dist[51][51], distw[51][51];
bool vis[51][51];
queue<pair<int, int>> q, qw;

pair<int, int> st, en;
vector<pair<int, int>> water;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    cin >> board[i];
  }

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      if (board[i][j] == '*')
        water.push_back({i, j});
      if (board[i][j] == 'S')
        st = {i, j};
      if (board[i][j] == 'D')
        en = {i, j};
    }

  for (int i = 0; i < R; i++)
    fill(distw[i], distw[i] + C, -1);

  for (auto w : water) {
    for (int i = 0; i < R; i++)
      fill(vis[i], vis[i] + C, false);

    qw.push({w.first, w.second});
    distw[w.first][w.second] = 0;
    vis[w.first][w.second] = true;

    while (!qw.empty()) {
      auto cur = qw.front();
      qw.pop();

      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
          continue;
        if (vis[nx][ny])
          continue;
        if (board[nx][ny] == 'X' || board[nx][ny] == 'D')
          continue;
        if (distw[nx][ny] != -1 &&
            distw[nx][ny] < distw[cur.first][cur.second] + 1)
          continue;

        distw[nx][ny] = distw[cur.first][cur.second] + 1;
        qw.push({nx, ny});
        vis[nx][ny] = true;
      }
    }
  }

  for (int i = 0; i < R; i++) {
    fill(dist[i], dist[i] + C, -1);
  }
  for (int i = 0; i < R; i++)
    fill(vis[i], vis[i] + C, false);

  q.push({st.first, st.second});
  dist[st.first][st.second] = 0;
  vis[st.first][st.second] = true;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= R || ny < 0 || ny >= C)
        continue;
      if (vis[nx][ny])
        continue;
      if (board[nx][ny] == 'X')
        continue;
      if (dist[nx][ny] != -1)
        continue;
      if (distw[nx][ny] != -1 &&
          distw[nx][ny] <= dist[cur.first][cur.second] + 1)
        continue;

      dist[nx][ny] = dist[cur.first][cur.second] + 1;
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }

  if (dist[en.first][en.second] == -1)
    cout << "KAKTUS";
  else
    cout << dist[en.first][en.second];
}
