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


 
int gcd(int a, int b, int& x, int& y) {
    if (!a) {
        x = 0, y = 1;
        return b;
    }
    int xx, yy, g = gcd(b % a, a, xx, yy);
    x = yy - b / a * xx;
    y = xx;
    return g;
}
 
inline int normal(int n) {
    n %= mod;
    (n < 0) && (n += mod);
    return n;
}
 
inline int inv(int a) {
    int x, y;
    assert(gcd(a, mod, x, y) == 1);
    return normal(x);
}
 
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return int(a * 1ll * b % mod); }
inline int _div(int a, int b) { return mul(a, inv(b)); }
 
inline int binPow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}
 

int main()
{
    int a;
    // int b;
    // int x;
    // int y;

    cout << "enter a:: \n";

    cin >> a;
    // cin >> b;

    // int ans = gcd(a, b, x, y);

    // cout << "gcd answer:: " << ans << endl;

    int ans2 = inv(a);

    cout << "inv answer:: " << ans2 << endl;

    return 0;
}