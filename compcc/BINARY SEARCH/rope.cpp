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

int a, b, n;

bool good(int x) {
    if (floor(x/a)*floor(x/b) >= n) return true;
    return false;
}

int main()
{
    cin >> a >> b >> n;

    int l = 0;
    int r = 1;
    while (good(r) == false) r*=2;

    while (l+1 < r) {
        int mid = l + (r - l) / 2;
        if (good(mid) == true) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << l ;

    return 0;
}