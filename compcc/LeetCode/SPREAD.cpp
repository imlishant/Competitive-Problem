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

vector<int> bittree;
vector<int> arr;
vector<int> diffarr;

class Fenwicktree {
public:
    int n;
    Fenwicktree(int n) {
        /*
        this->n = n+1;
        bittree.clear();
        bittree.assign(n+1, 0);
        */
        this->n = n+2;
        bittree.clear();
        bittree.assign(n+2, 0);
    }

    void update(int idx, int val) {
        while (idx < n && idx >= 0) {
            bittree[idx] += val;
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        int summ = 0;
        while (idx > 0) {
            summ += bittree[idx];
            idx -= (idx & -idx);
        }
        return summ;
    }

    void printBit() {
        cout << "bitTree:: ";
        for (int i = 1; i < n; i++) {
            cout << bittree[i] << " ";
        }
        cout << "\n";
    }

};

int main () {
    fast;

    int n, m, c;
    cin >> n >> m >> c;
    
    // Fenwicktree* ft = new Fenwicktree(n);
    // Fenwicktree ft = Fenwicktree(n);
    Fenwicktree ft(n);

    ft.update(1, c);
    ft.update(n+1, -c);


    while (m--) {

        char ch;
        cin >> ch;

        if (ch == 'S') {
            int u, v, k;
            cin >> u >> v >> k;
            ft.update(u, k);
            ft.update(v+1, -k);
        } else {
            int p;
            cin >> p;
            cout << ft.query(p) << endl;
        }
    }


    return 0;
}