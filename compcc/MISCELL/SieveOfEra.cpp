#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define for0(i,n) for(int i=0;i<n;++i)
#define for1(i,n) for(int i=1;i<=n;++i)
#define ford(i,n) for(int i=n-1;i>=0;--i)
#define forg(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
#define N 1000001
#define fast ios_base::sync_with_stdio(false),cin.tie(0);
#define deb(x) cout << #x << " " << x << endl;

// template<typename... T>
// void read(T&... args) {
//     ((cin >> args), ...);
// }

// template<typename... T>
// void write(T... args) {
//     ((cout << args << " "), ...);
// }


vector<bool> is_prime;

void sieve(int n) {

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (is_prime[i] == true) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

void printAllPrime(int n) {
    cout << "Prime: ";
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] == true) {
            cout << i << " ";
        }
    }
}

int main () {

    int n ;
    cin >> n;

    is_prime.resize(n+1, true);

    sieve(n);
    // cout << "is prime: " << is_prime[n] << endl;
    printAllPrime(n);
    return 0;
}