#include <bits/stdc++.h>

using namespace std;

string str1, str2;

int decode(string str) {
    int rst = 0;

    int cur = str.length() - 1;
    while(cur >= 0 && str[cur] == 'I') {
        rst++;
        cur--;
    }
    while(cur >= 0 && (str[cur] == 'V' || str[cur] == 'I')) {
        if(str[cur] == 'I') rst--;
        else rst += 5;
        cur--;
    }
    while(cur >= 0 && (str[cur] == 'X' || str[cur] == 'I')) {
        if(str[cur] == 'I') rst --;
        else rst += 10;
        cur--;
    }
    while(cur >= 0 && (str[cur] == 'L' || str[cur] == 'X')) {
        if(str[cur] == 'X') rst -= 10;
        else rst += 50;
        cur--;
    }
    while(cur >= 0 && (str[cur] == 'C' || str[cur] == 'X')) {
        if(str[cur] == 'X') rst -= 10;
        else rst += 100;
        cur--;
    }
    while(cur >= 0 && (str[cur] == 'D' || str[cur] == 'C')) {
        if(str[cur] == 'C') rst -= 100;
        else rst += 500;
        cur--;
    }
    while(cur >= 0 && (str[cur] == 'M' || str[cur] == 'C')) {
        if(str[cur] == 'C') rst -= 100;
        else rst += 1000;
        cur--;
    }
    return rst;
}   

string encode(int num) {
    string rst;
    int tmp = 0;
    while(num / 1000) {
        rst += 'M';
        num -= 1000;
    }
    while(num / 500) {
        rst += 'D';
        num -= 500;
    }
    while(num / 100) {
        rst += 'C';
        num -= 100;
    }
    while(num / 50) {
        rst += 'L';
        num -= 50;
    }
    while(num / 10) {
        rst += 'X';
        num -= 10;
    }
    while(num / 5) {
        rst += 'V';
        num -= 5;
    }
    while(num--)
        rst += 'I';

    size_t pos;

    if ((pos = rst.find("DCCCC")) != string::npos)
        rst.replace(pos, 5, "CM");
    if ((pos = rst.find("CCCC")) != string::npos)
        rst.replace(pos, 4, "CD");
    if ((pos = rst.find("LXXXX")) != string::npos)
        rst.replace(pos, 5, "XC");
    if ((pos = rst.find("XXXX")) != string::npos)
        rst.replace(pos, 4, "XL");
    if ((pos = rst.find("VIIII")) != string::npos)
        rst.replace(pos, 5, "IX");
    if ((pos = rst.find("IIII")) != string::npos)
        rst.replace(pos, 4, "IV");

    return rst;
}

int main() {
    cin >> str1 >> str2;

    // cout << decode(str1) << " " << decode(str2) << "\n";
    int rst = decode(str1) + decode(str2);
    cout << rst << "\n" << encode(rst);
}