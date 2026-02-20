#include <bits/stdc++.h>

using namespace std;

int n;
int ipt[100001];
int ipt2[100001];
int da[3] = {-1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> ipt[i];
    }

    if(n == 1) {
        cout << 0;
        return 0;
    }
    
    int rst, minRst = -1, d;

    for(int x1 = 0; x1 < 3; x1++) {
        for(int x2 = 0; x2 < 3; x2++) {
            copy(ipt, ipt + n, ipt2);
            ipt2[0] = ipt2[0] + da[x1];
            ipt2[1] = ipt2[1] + da[x2];

            rst = abs(da[x1]) + abs(da[x2]);
            d = ipt2[1] - ipt2[0];

            for(int i = 1; i <= n - 2; i++) {
                int next = ipt2[i] + d;
                if(abs(next - ipt2[i + 1]) > 1) {
                    rst = -1;
                    break;
                }
                rst += abs(next - ipt2[i + 1]);
                ipt2[i + 1] = next;
            }
            if(rst != -1) minRst = (minRst == -1 ? rst : min(minRst, rst));
        }
    }

    cout << minRst;
}