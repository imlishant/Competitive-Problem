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

bool binarysearch(vector<int> &arr, int &k) {
    int n = arr.size();
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (arr[mid] == k) {
            return true;
        } else if (arr[mid] < k) {
            l = mid+1;
        } else if (arr[mid] > k) {
            r = mid-1;
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> sortedarr(n);
    vector<int> query(k);


    for (int i = 0; i < n; i++) {
        cin >> sortedarr[i];
    }

    for (int i = 0; i < k; i++) {
        cin >> query[i];
    }

    // binary_search()

    bool ans;

    for (int i : query) {
        ans = binarysearch(sortedarr, i);
        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}