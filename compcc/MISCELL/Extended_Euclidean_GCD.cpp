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
    int xx = 0, yy = 0;
    int g = gcd(b % a, a, xx, yy);
    x = yy - b / a * xx;
    y = xx;
    return g;
}

int main()
{
    int a, b;
    int x = 0, y = 0;
    cout << "enter a & b:: \n";
    cin >> a;
    cin >> b;

    // if __gcd(a, b) == 1, then x is the modular multiplicative inverse 
    // OR simply x == inverse(a)

    int ans = gcd(a, b, x, y);

    cout << "extended gcd:: " << ans << ", x:: " << x << ", y:: " << y << endl;

    return 0;
}