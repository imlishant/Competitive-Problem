#include <bits/stdc++.h>
using namespace std;

// update for ordering of chars
// still not changed.

class Solution{
    vector<bool> visited;
	public:
	void topoSortUtil(int u, vector<int> adj[], stack<int>& Stack) {
        visited[u] = true;

        vector<int>::iterator it;
        
        for (it = adj[u].begin(); it != adj[u].end(); ++it) {
            if (visited[*it] == false) {
                topoSortUtil(*it, adj, Stack);
            }
        }
        Stack.push(u);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    stack<int> Stack;
	    
        visited.clear();
        visited.resize(V);
        
        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                topoSortUtil(i, adj, Stack);
            }
        }
        
        vector<int> ans;
        
        while (Stack.empty() == false) {
            int u = Stack.top();
            Stack.pop();
            ans.push_back(u);
        }
        
        return ans;
	}
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        //cout << check(N, res, adj) << endl;
        for (auto i : res) {
            cout << i << " ";
        }
    }
    
    return 0;
}