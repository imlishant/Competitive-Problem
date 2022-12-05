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

There is one meeting room in a firm. 
There are N meetings in the form of (start[i], end[i]) 
where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room 
when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)


*/

struct itemsCompare{
    bool operator () (const int item1, const int item2){
        return item1 > item2 ;
    }
};


/* WRONG SOLUTION, FIND WHYY??
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(vector<int> &start, vector<int> &end, int n)
    {
        // Your code here
        set<pair<int,int>> mm;
        set<int> m;
        // priority_queue<pair<int,int>> pq;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        //
        for (int i = 0; i < n; i++) {
            pq.push(end[i]);
        }
        //


        // sort(start, start+n);
        sort(start.begin(), start.end());
        //
        sort(end.begin(), end.end());

        cout << "\nSorted Start\n";
        for (int i = 0; i < n; i++) {
            cout << start[i] << " ";
        }

        cout << "\nSorted End\n";
        for (int i = 0; i < n; i++) {
            cout << end[i] << " ";
        }
        cout << "\n========\n";
        int meeting = 1;
        
        for (int i = 0; i < n; i++) {
            if (!pq.empty() && (start[i] > pq.top())) {
                cout << "start: " << start[i] << " \tend: " << pq.top() << "\n";
                meeting++;
                // m.insert(i+1);
                // m.insert(pq.top().second + 1);
                pq.pop();
            }
        }
        
        // return (int) m.size();
        return meeting;
    }
};
*/


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(vector<int> &start, vector<int> &end, int n)
    {
        if (n <= 1) return n;
        vector<pair<int,int>> interval;
        for (int i = 0; i < n; i++) {
            interval.push_back(make_pair(end[i], start[i]));
        }

        sort(interval.begin(), interval.end());

        /* GIVES TLE FOR LAST CASE, ERASE COMPLEXITY IS HIGH
        for (int i = 1; i < interval.size(); ) {
            if (interval[i].second <= interval[i-1].first) {    // NO COINCIDING INTERVAL THAT'S WHY <=
                cout << "out:: " << interval[i].second << "::" << interval[i].first << endl;
                interval.erase(interval.begin()+i);
                cout << "after:: " << interval[i].second << "::" << interval[i].first << endl;
            } else {
                i++;
            }
        }

        cout << "\nPair print\n";
        for (int i = 0; i < interval.size(); i++) {
            cout << interval[i].second << " :: " << interval[i].first << endl;
        }
        int ans = (int) interval.size();
        return ans;

        GIVES TLE
        */

        vector<pair<int,int>> anslist;
        anslist.push_back(interval[0]);
        for (int i = 1; i < interval.size(); i++) {
            if (interval[i].second > anslist.back().first) {
                anslist.push_back(interval[i]);
            }
        }
        int ans = (int) anslist.size();
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    
    fast;

    cout << "enter\n";

    int t;
    t = 1;
    // cin >> t;
    while (t--) {
        
        int n;
        // n = 6;
        n = 8;
        // cin >> n;

        // int start[n], end[n];
        /*
        vector<int> start = {1, 3, 0, 5, 8, 5};
        vector<int> end   = {2, 4, 6, 7, 9, 9};
        */

        vector<int> start = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
        vector<int> end   = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252};

        /*
        6
        1 3 0 5 8 5
        2 4 6 7 9 9

        8
        75250 50074 43659 8931 11273 27545 50879 77924
        112960 114515 81825 93424 54316 35533 73383 160252

        */

        // for (int i = 0; i < n; i++) cin >> start[i];

        // for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
