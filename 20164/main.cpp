#include <bits/stdc++.h>

using namespace std;

int n, maxN = 0, minN = INT_MAX;

int getDigit(int k) {
    int cnt = 0;

    while(k) {
        k /= 10;
        cnt++;
    }

    return cnt;
}

int countOdds(int k) {
    int cnt = 0;

    while(k) {
        if((k % 10) % 2 == 1) cnt++;
        k /= 10;
    }

    return cnt;   
}

void func(int k, int odds) {
    if(k < 10) {
        // cout << k << "\n";
        maxN = max(maxN, odds + countOdds(k));
        minN = min(minN, odds + countOdds(k));
        return;
    }

    if(k >= 10 && k < 100) {
        // cout << k << "\n";
        func(k / 10 + k % 10, odds + countOdds(k));
        return;
    }

    vector<int> order;
    int digit = getDigit(k);
    for(int i = 0; i < digit - 1 - 2; i++) {
        order.push_back(0);
    }
    order.push_back(1);
    order.push_back(1);

    do {
        int cur = 0, firstS = -1, secondS = -1;
        while(secondS == -1) {
            if(order[cur]) {
                if(firstS == -1) {
                    firstS = cur;
                } else {
                    secondS = cur;
                }
            }
            cur++;
        }
        int tmpK = k;
        // cout << tmpK << "->";

        int a =  tmpK / pow(10, digit - 1 - firstS);
        tmpK %= int(pow(10, digit - 1 - firstS));
        int b = tmpK / pow(10, digit - 1 - secondS);
        int c = tmpK % int(pow(10, digit - 1 - secondS));

        // cout << a << " " << b << " " << c << "\n";

        func(a + b + c, odds + countOdds(a) + countOdds(b) + countOdds(c));
    } while(next_permutation(order.begin(), order.end()));
}

int main() {
    cin >> n;

    func(n, 0);

    cout << minN << " " << maxN;
}