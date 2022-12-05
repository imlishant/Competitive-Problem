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

class Solution {
public:
      
    int binarysearch_count0(vector<int> &arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        if (arr[l] == 0) return n;
        if (arr[r] == 1) return 0;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if ((arr[mid] == 0) && (mid == 0 || arr[mid-1] == 1)) {
                return n - mid;
            } else if (arr[mid] == 0) {
                r = mid - 1;
            } else { 
                l = mid + 1;
            }
        }
        return -1;
    }
        
    int binarysearch_count1(vector<int> &arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        if (arr[l] == 0) return 0;
        if (arr[r] == 1) return n;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if ((arr[mid] == 1) && (mid == n-1 || arr[mid+1] == 0)) {
                return mid+1;
            } else if (arr[mid] == 1) {
                l = mid+1;
            } else { 
                r = mid-1;
            }
        }
        return -1;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> onecount; // count1, index
        for (int i = 0; i < m; i++) {
            vector<int> v = mat[i];
            int count1 = binarysearch_count1(v);
            onecount.push_back(make_pair(count1, i));
        }
        sort(onecount.begin(), onecount.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(onecount[i].second);
        }
        return ans;
    }

};

int main()
{
    fast;
    vector<vector<int>> mat = 
                                {{1,1,0,0,0},
                                {1,1,1,1,0},
                                {1,0,0,0,0},
                                {1,1,0,0,0},
                                {1,1,1,1,1}};

    int k = 3;

    Solution obj;

    vector<int> vv = obj.kWeakestRows(mat, k);
    for (int i : vv) {
        cout << i << " ";
    }


    return 0;
}