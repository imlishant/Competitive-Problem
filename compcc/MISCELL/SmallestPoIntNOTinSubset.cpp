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

int findSmallestPositiveIntegerNOTinAnySubset(vector<int>& v)
{
    int max = 0;
    if (v.empty() || (v[0] != 1)) {
        return 1;
    }
    // max = 1;
    // //starts from 1& added +1 already.
    // //start from index 1 of zero index;
    // only for this, max starts from 0
    max = 0;
    for (int i : v) {
        if (i > max+1) {
            break;
        }
        max += i;
    }

    // for (int i = 1; i < v.size(); i++) {
    //     if (v[i] > max+1) {
    //         break;
    //     }
    //     max += v[i];
    // }

    return max + 1;
}

int main()
{
    //sorted hai.
    vector<int> v = {1,1,3,5,8,21};
    int ans = findSmallestPositiveIntegerNOTinAnySubset(v);
    cout << "answer: " << ans;

    return 0;
}