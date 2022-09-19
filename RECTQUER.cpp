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

#define MAXN 1e9+7
#define M 301
#define D 10

int grid[M][M][D];
int mat[M][M];

int main () {
    // ios::sync_with_stdio(false);
    fast;
    memset(grid, 0, sizeof(grid));

    int n;
    cin >> n;

    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // cin >> mat[i][j];
            cin >> x;
            grid[i][j][x]++;
        }
    }

    //preprocessing.


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 10; k++) {
                grid[i][j][k] += grid[i-1][j][k] + grid[i][j-1][k] - grid[i-1][j-1][k];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x1, y1, x2, y2;
        int count = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int d = 1; d <= 10; d++) {
            if (grid[x2][y2][d] - grid[x2][y1-1][d] - grid[x1-1][y2][d] + grid[x1-1][y1-1][d] > 0) {
                count++;
            }
        }
        cout << count << endl;
    }


    return 0;
}