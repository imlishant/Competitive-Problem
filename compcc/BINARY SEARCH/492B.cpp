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

int main()
{
    fast;
    int n, l;
    cin >> n >> l;
    vector<int> a(1010);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // already declared vector of fixed size 1010, isliye sort only the first "n" elements
    sort(a.begin(), a.begin()+n);

    int res_by_2 = max(a[0] - 0, l - a[n-1]);
    int res = 2 * res_by_2;

    int maxi = INT_MIN;

    for (int i = 0; i < n-1; i++) {
        maxi = max(maxi, a[i+1] - a[i]);
    }

    maxi = max(res, maxi);

    cout << fixed << setprecision(9) << maxi/2.0 << endl;

    return 0;
}