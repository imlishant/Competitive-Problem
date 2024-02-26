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

When product (a*b) overflows before executing mod m, then we prefer this way multiplication;

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m) {
    long double x;
    uint64_t c;
    int64_t r;
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    x = a;
    c = x * b / m;
    r = (int64_t)(a * b - c * m) % (int64_t)m;
    return r < 0 ? r + m : r;
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

struct Congruence {
    long long a, m;
};

long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mod_inverse(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}

int main()
{

    vector<Congruence> congruences = {
        {2, 3},    // a = 2, m = 3
        {3, 5},    // a = 3, m = 4
        {2, 7}     // a = 1, m = 5
        // Add more Congruence structs as needed
    };

    long long result = chinese_remainder_theorem(congruences);

    cout << "CRT Result: " << result << endl;

    return 0;
}