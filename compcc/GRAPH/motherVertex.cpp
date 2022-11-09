#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<bool> visited;
    int M = 0;
	public:
 
    void DFSUtil(int u, vector<int> adj[]) {
        visited[u] = true;
        vector<int>::iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); ++it) {
            if (visited[*it] == false)
                DFSUtil(*it, adj);
        }
    }

    
    int findMotherVertex(int V, vector<int> adj[]) {
        
        visited.clear();
        visited.resize(V);

        for (int i = 0; i < V; ++i) {
            if (visited[i] == false) {
                DFSUtil(i, adj);
                M = i; // tracking last visited vertex.
            }
        }
        visited.clear();
        visited.resize(V);

        DFSUtil(M, adj); //call it again to see if it visits all vertices.
        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                return -1;
            }
        }
        return M;
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
    	cout << obj.findMotherVertex(V, adj) << "\n";
    }

    return 0;
}