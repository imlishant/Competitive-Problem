
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


vector<ll> factarr;
ll addmod(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

ll mulmod(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll powmod (ll a, ll b, ll c) {
    ll res = 1;
    a = a % c;
    if (a == 0) return 0;
    while (b > 0) {

        if (b&1) {
            res = (res%c * a%c) % c;
        }

        b = b>>1;
        a = (a%c * a%c) % c;

    }

    return (res % c);
}

ll fact(int n) {
    return factarr[n];
}

void factinit(int n) {

    factarr.clear();
    factarr.resize(n);

    factarr[0] = 1;
    factarr[1] = 1;

    for (int i = 2; i <= n; i++) {
        // factarr[i] = i * factarr[i-1];
        factarr[i] = mulmod(i, factarr[i-1]);
    }

}

ll inverse(ll a, ll p) {
    return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p) {
    // return ( ( ( (fact(n) % p) * (inverse(fact(k), p)) ) % p ) * (inverse(fact(n-k), p)) ) % p;
    return mulmod(mulmod(fact(n), inverse(fact(k), p)), inverse(fact(n-k), p));
}

/*
// theory
USED IN nCk to calc big integer denominator modulo

nCk = n!/((k!) * (n-k)!)
nCk (mod p) = ( (n!)*(mod p) * inv(k!)*(mod p) * inv((n-k)!)*(mod p) ) * (mod p)

---------------------------

a & p are co-prime.

a^p = a (mod p)
a^(p-1) = 1 (mod p)
a * inv(a) = a^(p-1) (mod p)
inv(a) = a^(p-2) (mod p)

USE ExpoModular.

a^b = ( (a^2) ^ (b/2) ) // even
a^b = ( a * a^(b-1) )

*/

bool check_num_is_good(int a, int b, ll num) {

    while (num > 0LL) {
        int c = num % 10;
        if (c != a && c != b) {
            return false;
        }
        num /= 10LL;
    }

    return true;
}

int solve(int a, int b, int n) {
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll sum = (ll) (i*a + (n-i)*b);
        if (check_num_is_good(a, b, sum)) {
            ans = addmod(ans, nCk(n, i, mod));
        }
    }
    return ans;
}

int main () {

    int a, b, n;
    cin >> a >> b >> n;

    const int N = 1e6 + 7;
    factinit(N);

    cout << solve(a, b, n) << endl;

    return 0;
}