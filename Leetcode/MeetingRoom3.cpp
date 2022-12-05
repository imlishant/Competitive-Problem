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

void solve(vector<vector<int>> calendar, int rooms, vector<vector<int>> query) {
    sort(calendar.begin(), calendar.end());
    priority_queue<int, vector<int>, greater<>> pq; //min_heap, used to store the end times of the current meetings
    
    vector<vector<int>> not_possible_intervals;
    
    for (const auto &interval : calendar) {
        while (!pq.empty() and pq.top() <= interval[0]) {
            pq.pop();
        }
        pq.push(interval[1]);
        if (pq.size() == rooms) { // rooms are full, after inserting the current interval
            not_possible_intervals.push_back({interval[0], pq.top()}); //will be in increasing order
        }
    }
    
    vector<bool> res;
    for (auto &q : query) {
        int lo = 0, hi = not_possible_intervals.size() - 1;
        int ind = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (not_possible_intervals[mid][1] <= q[0]) {
                ind = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (ind + 1 == not_possible_intervals.size()) res.push_back(true);
        else {
            res.push_back(max(not_possible_intervals[ind + 1][0], q[0]) >= min(not_possible_intervals[ind + 1][1], q[1]));
        }
    }
    
    for (auto r : res) {
        cout << r << " ";
    }
    cout << endl;
}

/*

GOOGLE/FACEBOOK

Given a list of intervals calendar and a number of available conference rooms. For each query, return true if the meeting can be added to the calendar successfully without causing a conflict, otherwise false. A conference room can only hold one meeting at a time.

Example 1:

Input: calendar = [[1, 2], [4, 5], [8, 10]], rooms = 1, queries = [[2, 3], [3, 4]]
Output: [true, true]
Example 2:

Input: calendar = [[1, 2], [4, 5], [8, 10]], rooms = 1, queries = [[4, 5], [5, 6]]
Output: [false, true]
Example 3:

Input:
calendar = [[1, 3], [4, 6], [6, 8], [9, 11], [6, 9], [1, 3], [4, 10]]
rooms = 3
queries = [[1, 9], [2, 6], [7, 9], [3, 5], [3, 9], [2, 4], [7, 10], [5, 9], [3, 10], [9, 10]]
Output: [false, true, false, true, false, true, false, false, false, true]

*/

int main()
{
    fast;

    solve({{1, 3}, {4, 6}, {6, 8}, {9, 11}, {6, 9}, {1, 3}, {4, 10}}, 3, {{1, 9}, {2, 6}, {7, 9}, {3, 5}, {3, 9}, {2, 4}, {7, 10}, {5, 9}, {3, 10}, {9, 10}});
    solve({{1, 2}, {4, 5}, {8, 10}}, 1, {{4, 5}, {5, 6}});
    return 0;
}