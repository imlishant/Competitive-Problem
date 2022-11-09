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



ll inverse(ll a, ll p) {
    return powmod(a, p-2, p);
}

/*
// theory
USED IN nCk to calc big integer denominator modulo

nCk = n!/((k!) * (n-k)!)
nCk (mod p) = ( (n!)*(mod p) * inv(k!)*(mod p) * inv((n-k)!)*(mod p) ) * (mod p)

---------------------------

a^p = a (mod p)
a^(p-1) = 1 (mod p)
a * inv(a) = a^(p-1) (mod p)
inv(a) = a^(p-2) (mod p)

USE ExpoModular.

a^b = ( (a^2) ^ (b/2) ) // even
a^b = ( a * a^(b-1) )

*/



int main () {

    int a, b, c;
    // ll a, b, c;
    cin >> a >> b >> c;
    // 71045970 41535484 64735492

    return 0;
}