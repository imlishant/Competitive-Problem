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

vector<ll> bittree;
vector<ll> arr;

class Fenwicktree {
public:
    ll len = 0;
    void init(ll n) {
        len = n+1;
        bittree.clear();
        bittree.assign(n+1, 0);
        arr.assign(n+1, 0);
    }

    ll LSB(ll i) {
        return (i & (-i));
    }

    void build() {
        for (ll i = 1; i < len; i++) {
            update(i, arr[i]);
        }
    }

    void update(ll i, ll val) {
        while (i < len) {
            bittree[i] += val;
            i += (i & (-i));
        }
    }
    
    ll query(ll a) {
        ll summ = 0;
        while (a > 0) {
            summ += bittree[a];
            a -= (a & (-a));
        }
        return summ;
    }

    ll rangesum(ll a, ll b) {
        return query(a) - query(b-1);
    }

    void print() {
        cout << "bit-tree:: ";
        for (ll i = 1; i < len; i++) {
            cout << bittree[i] << " ";
        }
    }

};

int main () {
    fast;
    ll n, q;
    cin >> n >> q;


    Fenwicktree f;
    f.init(n);

    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    f.build();

    while (q--) {
        char ch;
        ll a, b;
        cin >> ch >> a >> b;
        a++;

        if (ch == 'G') {
            arr[a] += b;
            f.update(a, b);
        } else if (ch == 'T') {
            arr[a] -= b;
            f.update(a, -b);
        } else if (ch == 'S') {
            b++;
            f.print();
            cout << "\nquery:: " << f.rangesum(b, a) << endl;
        }
    }

    // query to prll = summ of index i to j;
    // add + OR -

    return 0;
}