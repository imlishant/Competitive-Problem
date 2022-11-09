#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "gcd :: " << __gcd(20, 46);
    return 0;
}

// pouring code.
// m < n & d < n;
// 1. mjug full kro -> agr empty hai
// 2. njug empty kro -> agr full hai
// 3. mjug to njug

// opt code.
// diphontine equation
// case check (n/gcd) * gcd == n, then fine
void pouring (int mjug, int njug, int mcap, int ncap) {
    if (mjug == d || njug == d) {
        break;
    }
    else if (mjug == 0) {
        mjug = mcap;
    }
    else if (njug == ncap) {
        njug = 0;
    }
    else if (mjug == mcap && njug != ncap) {
        njug = mjug + ncap - mjug, 2*mcap < ncap;
        // 2*mcap + x = ncap
        // 2*mcap = ncap + x
        // a*mcap + x = ncap
    }
}

int diphontine(int mcap,int ncap, int d) {
    // n= mq + k;
}