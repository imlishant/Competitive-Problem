#include <bits/stdc++.h>
using namespace std;

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

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cout << "N & E, in order enter:: ";
        cin >> N >> E;
        int u, v;

        vector<int> adj[N];

        cout << "\nenter edges:\n";
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << "\nprint topsort: ";
        for (int i : res) cout << i << " ";
        cout << "\n\n";

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}