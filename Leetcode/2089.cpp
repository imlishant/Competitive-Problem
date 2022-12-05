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

    vector<int> targetIndices(vector<int>& nums, int target) {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        int left = ileft(nums, target);
        int right = iright(nums, target);

        vector<int> ans;
        
        for (int i = left; i < right; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    fast;
    /*
    int n, tar;
    cin >> n >> tar;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    */

    int n = 5;
    vector<int> arr = {2,1,2,2,5};
    int tar = 2;

    Solution obj;

    vector<int> anss = obj.targetIndices(arr, tar);
    for (int i : anss) {
        cout << i << " ";
    }

    return 0;
}