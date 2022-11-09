#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> visited;
    vector<bool> recStack;
public:
    bool isCyclicUtil(int u, vector<int> adj[]) {
        if (visited[u] == false) {
            visited[u] = true;
            recStack[u] = true;
            
            vector<int>::iterator it;
            
            for (it = adj[u].begin(); it != adj[u].end(); ++it) {
                if ((visited[*it] == false) && isCyclicUtil(*it, adj)) {
                    return true;
                } else if (recStack[*it]) {
                    return true;
                }
            }
        }
        recStack[u] = false;
        return false;
    }

	bool isCyclic(int V, vector<int> adj[]) {
        visited.clear();
        recStack.clear();

        visited.resize(V);
        recStack.resize(V);

	   	for (int i = 0; i < V; i++) {
	   	    if (isCyclicUtil(i, adj))
	   	        return true;
	   	}
	   	return false;
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
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
