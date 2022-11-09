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

vector<int> diffArray;

// range update => O(1);
// point query => O(n);

class Diff {
public:

    void init(vector<int>& arr) {
        int n = (int) arr.size();
        diffArray.clear();
        diffArray.assign(n, 0);

        diffArray[0] = arr[0];
        for (int i = 1; i < n; i++) {
            diffArray[i] = arr[i] - arr[i-1];
        }
    }

    void update(int l, int r, int x) {
        diffArray[l] += x;
        diffArray[r+1] -= x;
    }

    int getElement(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> ans(n);
        ans[0] = diffArray[0];
        for (int i = 1; i < n; i++) {
            ans[i] = arr[i] + diffArray[i];
        }
        return ans[d];
    }

};

int main () {
    ios::sync_with_stdio(false);
    vector<int> arr = {2,3,5,1,5,7,4,6,9};

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\nbuild\n";

    Diff dd;
    dd.init(arr);

    int queries;
    cin >> queries;

    while (queries--) {
        int q;
        cin >> q;
        if (q == 1) {
            int l, r, x;
            dd.update(l, r, x);
        } else {
            int i;
            cout << dd.getElement(arr, i) << endl;
        }
    }

    return 0;

}
