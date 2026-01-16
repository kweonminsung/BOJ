#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> words;
int baseMask;

int dfs(int idx, int cnt, int mask, vector<int>& cand) {
    if (cnt == 0 || idx == cand.size()) {
        int r = 0;
        for (int w : words) {
            if ((w & ~mask) == 0) r++; // word is readable
        }
        return r;
    }

    int best = 0;
    for (int i = idx; i < cand.size(); i++) {
        best = max(best, dfs(i + 1, cnt - 1, mask | (1 << cand[i]), cand));
    }
    return best;
}

int main() {
    cin >> n >> k;

    if (k < 5) {
        cout << 0;
        return 0;
    }

    baseMask = 0;
    for (char c : {'a','n','t','i','c'}) baseMask |= 1 << (c - 'a');

    vector<bool> usedLetter(26, false);

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int mask = 0;
        for (char c : s) {
            if (!(c == 'a'|| c == 'n' || c == 't' || c == 'i' || c == 'c')) {
                mask |= 1 << (c - 'a');
                usedLetter[c - 'a'] = true;
            }
        }
        words.push_back(mask);
    }

    vector<int> cand;
    for (int c = 0; c < 26; c++) {
        if (!((baseMask >> c) & 1) && usedLetter[c]) {
            cand.push_back(c);
        }
    }

    int extra = k - 5;
    if (extra >= cand.size()) {
        cout << n;
        return 0;
    }

    cout << dfs(0, extra, baseMask, cand);
}
