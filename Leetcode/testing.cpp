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


/*
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



};

int main()
{
    fast;

    //REVERSE SORTED BINARY ARRAY   
    vector<int> arr = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };

    Solution obj;

    int count0 = obj.binarysearch_count0(arr);
    int count1 = obj.binarysearch_count1(arr);
    
    cout << "\nzero : " << count0;
    cout << "\none  : " << count1 << endl;

    return 0;
}
*/

 
void print_container(const std::vector<int>& c) 
{
    for (int i : c)
        std::cout << i << " ";
    std::cout << '\n';
}

int main( )
{
    fast;
    std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Erase all even numbers
    /*
    for (std::vector<int>::iterator it = c.begin(); it != c.end();)
    {
        if (*it % 2 == 0)
            it = c.erase(it);
        else
            ++it;
    }
    */

    for (int i = 0; i < c.size(); ) {
        if (c[i] % 2 == 0) {
            cout << "before:: " << c[i] << endl;
            c.erase(c.begin()+i);
            cout << "afterr:: " << c[i] << endl;
        } else {
            cout << "nothing:: " << c[i++] << endl;
        }
    }
    cout << "\nSize :: " << c.size() << "\n";
    print_container(c);
}