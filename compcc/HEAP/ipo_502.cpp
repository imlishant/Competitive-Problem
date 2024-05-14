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



#define pp pair<int, int>

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int projectsNum = profits.size();
        priority_queue<pp, vector<pp>, greater<pp>> minCapHeap;
        priority_queue<int> maxProfitHeap;

        for (int i = 0; i < projectsNum; i++) {
            minCapHeap.push({capital[i], profits[i]});
        }

        while (k--) {
            while (!minCapHeap.empty() && (minCapHeap.top().first <= w)) {
                maxProfitHeap.push(minCapHeap.top().second);
                minCapHeap.pop();
            }

            if (maxProfitHeap.empty()) {
                break;
            }
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return w;
    }
};

int main() 
{
    int k = 3;
    int w = 0;
    vector<int> profit = {1,2,3};
    vector<int> capital = {0,1,2};

    Solution obj;
    int ans = obj.findMaximizedCapital(k, w, profit, capital);

    cout << "\nANSWER:: " << ans << endl;

    return 0;
}