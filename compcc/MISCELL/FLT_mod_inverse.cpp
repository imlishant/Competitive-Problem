#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vector<int>>
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define for0(i,n) for(int i=0;i<n;++i)
#define for1(i,n) for(int i=1;i<=n;++i)
#define ford(i,n) for(int i=n-1;i>=0;--i)
#define forg(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL);
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
ll mul_mod(ll a, ll b, ll c) {
    ll x = (a) % (c);
    ll y = (b) % (c);
    ll ans = ((x) * (y)) % (c);
    return ans;
}
*/

ll mul_mod(ll a, ll b, ll m) {
    return ((a%m) * (b%m)) % m;
}

ll bin_pow_mod (ll a, ll b, ll m) {
    ll res = 1;
    a = a % m;
    if (a == 0) return 0;
    while (b > 0) {

        if (b&1) {
            res = mul_mod(res, a, m);
        }

        b = b>>1;
        a = mul_mod(a, a, m);

    }

    return (res % m);
}

ll mod_inverse(ll a, ll p) {
    return bin_pow_mod(a, p-2, p);
}


int main() {
    ll a, p;

    cout << "enter a & p:: \n";
    cin >> a;
    cin >> p;

    cout << "inverse using fermat/euler:: " << mod_inverse(a, p) << endl;


    return 0;
}