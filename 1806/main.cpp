#include <bits/stdc++.h>

using namespace std;

int n, s;
int arr[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;

  for(int i = 0; i < n; i++)
    cin >> arr[i];

  int start = 0, end = 0, tot = arr[0], rst = INT_MAX;
  bool sFlag = false, eFlag = false;

  while(start < n && end < n) {
    tot += (sFlag ? -arr[start - 1] : 0) + (eFlag ? arr[end] : 0);
    // cout << start << " " << end << " " << tot << "\n";
    
    if(tot >= s) {
      rst = min(rst, end - start + 1);
      start++;
      sFlag = true;
      eFlag = false;

      if(start > end) {
        end++;
        eFlag = true;
      }
    } else {
      end++;
      sFlag = false;
      eFlag = true;
    }
  }

  cout << (rst == INT_MAX ? 0 : rst);
}
