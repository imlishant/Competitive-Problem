#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<bool> visited;
    stack<int> Stack;
	public:
    // topological filling
    void fillStackDFS(int u, vector<int> adj[]) {
        visited[u] = true;
        vector<int>::iterator it;
        
        for (it = adj[u].begin(); it != adj[u].end(); ++it) {
            if (visited[*it] == false) {
                fillStackDFS(*it, adj);
            }
        }
        Stack.push(u);
    }
    
    // dfs for transpose
    void DFSTr(int u, vector<int> radj[]) {
        visited[u] = true;
        vector<int>::iterator it;
        for (it = radj[u].begin(); it != radj[u].end(); ++it) {
            if (visited[*it] == false)
                DFSTr(*it, radj);
        }
    }
    
    void transpose(int V, vector<int> radj[], vector<int> adj[]) {
        for (int i = 0; i < V; i++) {
            vector<int>::iterator it;
            for (it = adj[i].begin(); it != adj[i].end(); ++it) {
                radj[*it].push_back(i);
            }
        }
    }
    
    int kosaraju(int V, vector<int> adj[]) {
        
        while (Stack.empty() == false) Stack.pop();
        
        visited.clear();
        visited.resize(V);

        //full dfs topological
        for (int i = 0; i < V; ++i) {
            if (visited[i] == false) {
                fillStackDFS(i, adj);
            }
        }
        vector<int> radj[V];
        transpose(V, radj, adj);
        
        visited.clear();
        visited.resize(V);

        int ssc = 0;
        while (Stack.empty() == false) {
            int u = Stack.top();
            Stack.pop();
            
            if (visited[u] == false) {
                DFSTr(u, radj);
                ssc++;  
            }
        }
        return ssc;
    }
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}