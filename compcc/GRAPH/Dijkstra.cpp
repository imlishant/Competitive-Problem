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


class Graph 
{
    // map<int, int> visited;
    vector<vector<int>> adj;
    bool detectCycleUtil (vector<int>& visited, int v);
public:
    
    void addEdge(int u, int v);
    bool detectCycle(int n);
};

void Graph::addEdge (int u, int v) {
    adj[u].push_back(v);
}




int main () {
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(2,3);

    int n = 4;

    cout << "isCycleThere:: " ;
    cout << g.detectCycle(n);

    return 0;
}