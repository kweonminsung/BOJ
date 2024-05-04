#include <bits/stdc++.h>

using namespace std;

int student[101];
int firstStd[101];

int N, M;
list<int> album;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  fill(firstStd, firstStd + 101, -1);

  int input;
  for (int i = 0; i < M; i++) {
    cin >> input;

    if (student[input] != 0) {
      student[input]++;
      continue;
    }

    if (album.size() == N) {
      int minN = album.front();
      vector<int> minV;
      for (int x : album) {
        if (student[x] < student[minN]) {
          minN = x;
          minV.clear();
          minV.push_back(x);
        } else if (student[x] == student[minN]) {
          minV.push_back(x);
        }
      }

      if (minV.size() == 1) {
        album.erase(find(album.begin(), album.end(), minN));
        student[minN] = 0;
        firstStd[minN] = -1;
      } else {
        int minNR = minV.front();
        for (int x : minV) {
          if (firstStd[x] < firstStd[minNR])
            minNR = x;
        }
        album.erase(find(album.begin(), album.end(), minNR));
        student[minNR] = 0;
        firstStd[minNR] = -1;
      }
    }
    album.push_back(input);
    student[input]++;
    firstStd[input] = firstStd[input] == -1 ? i : firstStd[input];
  }

  album.sort();

  for (int x : album)
    cout << x << " ";
}
