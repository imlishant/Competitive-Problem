#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    bool isHappy(int n) {
        while (1) {
            int nn = 0;
            if (n < 10) break;
            while (n) {
                nn += (n%10) * (n%10);
                n /= 10;
            }
            n = nn;
        }
        if (n == 1 || n == 7) return true;
        return false;
    }
    */

    int next(int n) {
            int nn = 0;
            while (n) {
                nn += (n%10) * (n%10);
                n /= 10;
            }
            return nn;
    }

    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));

        while(slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};

int main() {
    Solution obj;
    int n = 7;
    bool ans = obj.isHappy(n);
    cout << "n:: " << ans << endl;
    return 0;
}