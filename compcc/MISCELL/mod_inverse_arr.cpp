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

// recursive modular inverse
int mod_inv(int a) {
    return (a <= 1) ? a : mod - (ll) (mod / a) * mod_inv(mod % a) % mod;
}

// pre-compute in the range [1, size_m-1], O(size_m)
vector<int> inv(mod, 0);

void precompute_mod_inverse(int size_m) {
    inv[1] = 1;

    for (int a = 2; a < size_m; a++) {
        inv[a] = mod - (ll) (mod / a) * inv[mod % a] % mod;
    }
}

// modular inverse of array of numbers modulo m
std::vector<int> invs(const std::vector<int> &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    std::vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    // int x, y;
    // extended_euclidean(v, m, x, y);
    // x = (x % m + m) % m;
    int x = mod_inv(v);
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}