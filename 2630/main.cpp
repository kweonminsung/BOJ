#include <bits/stdc++.h>

using namespace std;

int n, totB, totW;
int arr[130][130];

int shit(int x, int y, int size, bool isBlue) {
    if(size == 1) {
        totB += isBlue ? arr[x][y] : 0;
        totW += isBlue ? 0 : !arr[x][y];
        return isBlue ? arr[x][y] : !arr[x][y];
    }

    int a = shit(x, y, size / 2, isBlue);
    int b = shit(x, y + size / 2, size / 2, isBlue);
    int c = shit(x + size / 2, y, size / 2, isBlue);
    int d = shit(x + size / 2, y + size / 2, size / 2, isBlue);

    if(a + b + c + d == size * size){
        totB += (isBlue ? (1 - 4) : 0);
        totW += (isBlue ? 0 : (1 - 4));
    }
    
    return a + b + c + d;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    }


    shit(0, 0, n, 0);
    shit(0, 0, n, 1);
    cout << totW << "\n" << totB;
}
