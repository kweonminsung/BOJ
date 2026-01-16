#include <bits/stdc++.h>

using namespace std;

long long n;
pair<long long, long long> p[10010];

int main() {
    cin >> n;

    for(long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    double rst = 0;
    for(long long i = 0; i < n - 1; i++) {
        rst += p[i].first * p[i + 1].second - p[i + 1].first * p[i].second;
    }
    rst += p[n - 1].first * p[0].second - p[0].first * p[n - 1].second;

    printf("%0.1f", round(abs(rst) / 2 * 10) / 10);
}