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

#define MAXN 1000

class segtree {

public:
    vector<long long> sum;
    int siz = 1;

    void init(int n) {
        siz = 1;
        while (siz < n) siz *= 2;
        sum.assign(2*siz, 0LL);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i < m) {
            update(i, v, 2*x+1, lx, m);
        } else {
            update(i, v, 2*x+2, m, rx);
        }
        sum[x] = sum[2*x+1] + sum[2*x+2];
    }

    void update(int i, int v) {
        update(i, v, 0, 0, siz);
    }

    void build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int) arr.size()) {
                sum[x] = arr[lx];
            }
            return;
        }
        int m = lx + (rx - lx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        sum[x] = sum[2*x+1] + sum[2*x+2];
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, siz);
    }

    long long sums(int l, int r, int x, int lx, int rx) {
        if ( lx >= r || rx <= l ) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return sum[x];
        }
        long long left = 0, right = 0;
        int m = lx + (rx - lx) / 2;
        left = sums(l, r, 2*x+1, lx, m);
        right = sums(l, r, 2*x+2, m, rx);
        return left+right;
    }

    long long sums(int l, int r) {
        return sums(l,r,0,0,siz);
    }
};

int main () {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    st.build(arr);

    /*
    // for inpurt array we build seg tree
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.update(i, v);
    }
    */

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            st.update(i,v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.sums(l,r) << endl;
        }
    }

    return 0;
}