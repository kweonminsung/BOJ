#include <bits/stdc++.h>

using namespace std;

int t;

int getMonthSize(int y, int m) {
    switch(m) {
        case 2:
            if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
    }
}

int calDiff(int y, int aM, int aD, int bM, int bD) {
    if(aM == bM && aD == bD) {
        return 0;
    } else if(aM == bM) {
        return bD - aD;
    } else if(aM == 12 && bM == 1) {
        return bD + 31 - aD;
    } else if(aM == 1 && bM == 12) {
        return bD - 31 - aD;
    } else if(aM + 1 == bM) {
        return bD + getMonthSize(y, aM) - aD;
    } else if(bM + 1 == aM) {
        return bD - getMonthSize(y, bM) - aD;
    } else {
        return 999;
    }
}
int calSubY(int y, int dueM, int dueD, int diff) {
    if(dueM == 12 && dueD + diff > 31) return y + 1;
    else if(dueM == 1 && dueD + diff < 1) return y - 1;
    else return y;
}

int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        int dueM, dueD, dueY, subM, subD;
        scanf("%d/%d/%d", &dueM, &dueD, &dueY);
        scanf("%d/%d", &subM, &subD);

        int diff = calDiff(dueY, dueM, dueD, subM, subD);
        if(diff == 0) printf("SAME DAY\n");
        else if(diff == 999 || diff > 7 || diff < -7) printf("OUT OF RANGE\n");
        else if(diff > 0) {
            if(diff == 1)
                printf("%d/%d/%d IS %d DAY AFTER\n", subM, subD, calSubY(dueY, dueM, dueD, diff), diff);
            else 
                printf("%d/%d/%d IS %d DAYS AFTER\n", subM, subD, calSubY(dueY, dueM, dueD, diff), diff);
        } else {
            if(diff == -1)
                printf("%d/%d/%d IS %d DAY PRIOR\n", subM, subD, calSubY(dueY, dueM, dueD, diff), -diff);
            else
                printf("%d/%d/%d IS %d DAYS PRIOR\n", subM, subD, calSubY(dueY, dueM, dueD, diff), -diff);
        }
    }
}