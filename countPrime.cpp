#include <bits/stdc++.h>
using namespace std;

#define N 5e6

// vector<bool> isprime(N, true);
int countp = 0;

class Solution {
public:

    void sieve (int n) {
        vector<bool> isprime (n+1, true);

        isprime[0] = isprime[1] = false;
        int i = 0;
        countp = 0;
        for (i = 2; i*i <= n; i++) { // this stops from overflow.
            if (isprime[i] == true) {
                countp++;
                for (int j = i*i; j <= n; j+=i) {
                    isprime[j] = false;
                }
            }
        }

        for (; i < n; i++) {
            if (isprime[i] == true) {
                countp++;
            }
        }
    }

    int countPrimes(int n) {
        sieve(n);
        return countp;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    int ans = obj.countPrimes(n);
    
    cout << "Ans:: " << ans << endl;
    
    return 0;
}