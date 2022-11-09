// (a^b)%c
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

/*

// small numbers -> a, b, c;
// simple: no overflow

int power (int a, int b, int c) {
    int res = 1;

    while (b > 0) {

        if (b&1) {
            res = (res * a);
        }

        b = b>>1;
        a = (a * a);

    }

    cout << "ans: " << res << endl;
    return (res % c);
}

*/

/*
// INT
// big int/long long numbers -> a, b, c;
// complex: int overflow may occur

int power (int a, int b, int c) {
    int res = 1;
    a = a % c;
    if (a == 0) return 0;
    cout << "a = " << a << endl;
    while (b > 0) {

        if (b&1) {
            res = (res%c * a%c) % c;
            cout << "res(" << b << ") ODD: " << res << " ; a = " << a << endl;
        }

        b = b>>1;
        a = (a%c * a%c) % c;
        if (a < 0) a += c;
        cout << "a(" << b << ") : " << a << endl;

    }

    // cout << "ans: " << res << endl;
    return (res % c);
}
*/


// LONG LONG INT
// big int/long long numbers -> a, b, c;
// complex: int overflow may occur

ll power (ll a, ll b, ll c) {
    ll res = 1;
    a = a % c;
    if (a == 0) return 0;
    cout << "a = " << a << endl;
    while (b > 0) {

        if (b&1) {
            res = (res%c * a%c) % c;
            cout << "res(" << b << ") ODD: " << res << " ; a = " << a << endl;
        }

        b = b>>1;
        a = (a%c * a%c) % c;
        // if (a < 0) a += c;
        cout << "a(" << b << ") : " << a << endl;

    }

    // cout << "ans: " << res << endl;
    return (res % c);
}

int pow(int A, int B, int C) 
{
    int pow = 1;
    for(int i = 0; i < B; i++)
    {
        pow = pow * A;
    }
    if(pow < 0)
    {
        pow = pow * -1;
    }
    return pow % C;
}

/*
// INT/LONG LONG INT
// big int/long long numbers -> a, b, c;
// complex: int overflow may occur

ll power (int a, int b, int c) {
    ll res = 1;
    a = a % c;
    if (a == 0) return 0;
    cout << "a = " << a << endl;
    while (b > 0) {

        if (b&1) {
            res = (res%c * a%c) % c;
            cout << "res(" << b << ") ODD: " << res << " ; a = " << a << endl;
        }

        b = b>>1;
        a = (a%c * a%c) % c;
        // if (a < 0) a += c;
        cout << "a(" << b << ") : " << a << endl;

    }

    // cout << "ans: " << res << endl;
    return (res % c);
}
*/


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
    // answer = 30222236
    cout << "pow(a,b)mod(c): " << power(a,b,c) << endl;
    // cout << "pow(a,b)mod(c): " << pow(a,b,c) << endl;

    return 0;
}

/*
mod+ans;

 -1 % 20 = -1
 ==> 
 (-1) = 20 * x + rem;
x = -1;

20 * (0) + (-1)
20 * (-1) + 19

-22
20(-1) + (-2)
20(-2) + (18)
*/