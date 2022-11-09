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

vector<int> tree;

class finwickTree {
public:

    void init(vector<int>& arr) {
        int n = arr.size();
        int size2 = 1;
        while (size2 < n) size2 <<= 1;
        tree.resize(size2 + 1);

        for (int i = 0; i < arr.size(); i++) {
            tree[i+1] = arr[i];
        }
    }


    void build(vector<int>& arr) {
        tree.clear();
        /*
        tree.resize(arr.size()+1);
        // tree.assign(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            tree[i+1] = arr[i];
        }
        */

        init(arr);

        for (int i = 1; i < tree.size(); i++) {
            int p = i + (i & -i); // index immediate parent
            if (p < tree.size()) {
                tree[p] = tree[p] + tree[i];
            }
        }
    }

    int query_sum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }

    void oper_update(int index, int value) { // add to current index
        while (index < tree.size()) {
            tree[index] += value;
            index += (index & -index);
        }
    }
};

int main () {
    ios::sync_with_stdio(false);
    vector<int> arr = {2,3,5,1,5,7,-4,6,9};

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\nbuild\n";

    finwickTree ft;
    ft.build(arr);

    for (int i = 1; i < tree.size(); i++) {
        cout << tree[i] << " ";
    }

    cout << "\nOper: ";
    cout << ft.query_sum(5) << endl;

    return 0;
}