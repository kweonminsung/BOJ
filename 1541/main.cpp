#include <bits/stdc++.h>

using namespace std;

string str;

vector<int> nums;
vector<char> op;


int main() {
    cin >> str;
     
    int cur = 0;
    for(cur = 0; cur < str.length();) {
        int cnt = 1;
        while(cur + cnt - 1 < str.length() && str[cur + cnt - 1] != '-' && str[cur + cnt - 1] != '+') cnt++;

        nums.push_back(stoi(str.substr(cur, cnt - 1)));

        if(cur + cnt < str.length())
            op.push_back(str[cur + cnt - 1]);
        cur += cnt;
    }

    // for(auto x: nums)
    //     cout << x << " ";
    // for(auto x: op)
    //     cout << x << " ";

    int rst = nums[0];
    bool hasMinus = false;
    for(int i = 1; i < nums.size(); i++) {
        hasMinus = op[i - 1] == '-' ? true : hasMinus;

        if(!hasMinus) rst += nums[i];
        else rst -= nums[i];
    }

    cout << rst;
}