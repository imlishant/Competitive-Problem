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


int iright(vector<int> &arr, int &k) {
    int n = arr.size();
    int l = -1;
    int r = n;
    while (l+1 < r) {
        int mid = l + (r-l)/2;

        if (arr[mid] <= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int ileft(vector<int> &arr, int &k) {
    int n = arr.size();
    int l = -1;
    int r = n;
    while (l+1 < r) {
        int mid = l + (r-l)/2;

        if (arr[mid] < k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int main()
{
    int n, k;
    cin >> n; 
    vector<int> sortedarr(n);

    for (int i = 0; i < n; i++) {
        cin >> sortedarr[i];
    }

    cin >> k;

    sort(sortedarr.begin(), sortedarr.end());

    int left;
    int right;


    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l;
        cin >> r;
        left = ileft(sortedarr, l);
        right = iright(sortedarr, r);
        cout << right - left << endl;
    }

    // 1 3 4 10 10 


// 10 <= last 10
// 10 last rightmost index
// 1 first leftmost index
/*

5
10 1 10 3 4
4
1 10
2 9
3 4
2 2

*/

    return 0;
}