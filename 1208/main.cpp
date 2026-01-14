#include <bits/stdc++.h>

using namespace std;

long n, s;
long arr[50];
bool used[50];
vector<long> ableSumLeft, ableSumRight;

void get_all_sums(long n, long end, long sum, bool isLeft) {
    if(n > end) {
        if(isLeft) ableSumLeft.push_back(sum);
        else ableSumRight.push_back(sum);

        return;
    }
    
    used[n] = true;
    get_all_sums(n + 1, end, sum + arr[n], isLeft);

    used[n] = false;
    get_all_sums(n + 1, end, sum, isLeft);
}

int main() {
    cin >> n >> s;

    for(long i = 0; i < n; i++)
        cin >> arr[i];

    long leftS = 0, leftE = n / 2, rightS = n / 2 + 1, rightE = n - 1;

    get_all_sums(leftS, leftE, 0, true);
    get_all_sums(rightS, rightE, 0, false);

    sort(ableSumLeft.begin(), ableSumLeft.end());
    sort(ableSumRight.begin(), ableSumRight.end());

    // for(auto x : ableSumLeft)
    //     cout << x << " ";
    // cout << "|";
    // for(auto x : ableSumRight)
    //     cout << x << " ";
    // cout << "\n\n";

    long rst = 0;
    for(long x : ableSumLeft) {
        long dest = s - x;
        if(binary_search(ableSumRight.begin(), ableSumRight.end(), dest)) {
            rst += upper_bound(ableSumRight.begin(), ableSumRight.end(), dest) - lower_bound(ableSumRight.begin(), ableSumRight.end(), dest);
        }
    }

    if(s == 0) cout << rst - 1;
    else cout << rst;
}