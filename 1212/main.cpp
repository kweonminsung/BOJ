#include <bits/stdc++.h>

using namespace std;

string convertTo2(char c, bool padding) {
    switch (c)
    {
        case '0':
            return padding ? "000" : "";
        case '1':
            return padding ? "001" : "1";
        case '2':
            return padding ? "010" : "10";
        case '3':
            return padding ? "011" : "11";
        case '4':
            return padding ? "100" : "100";
        case '5':
            return padding ? "101" : "101";
        case '6':
            return padding ? "110" : "110";
        case '7':
            return padding ? "111" : "111";
    }
}

int main() {
    string str;
    cin >> str;

    if(str == "0") {
        cout << "0";
        return 0;
    }

    for(int i = 0; i < str.length(); i++) {
        cout << convertTo2(str[i], i != 0);
    }
}