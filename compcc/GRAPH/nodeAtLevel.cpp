#include<bits/stdc++.h>
using namespace std;


class Solution
{
    vector<bool> visited;
    map<int, int> m;
    
	public:
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    visited.clear();
        visited.resize(V);
	    
	    queue<int> q;
	    int v = 0;
        q.push(v);
        visited[v] = true;
        int lvl = 0;
        int nodeAtlvl = 0;
        m[v] = lvl;

        vector<int>::iterator it;

        while (q.empty() == false) {
            nodeAtlvl = q.size();
            lvl++;
            while (nodeAtlvl--) {
                int u = q.front();
                q.pop();
                for (it = adj[u].begin(); it != adj[u].end(); ++it) {
                    
                    if (visited[*it] == false) {
                        visited[*it] = true;
                        m[*it] = lvl;
                        q.push(*it);
                    }
                }
            }
        }
        if (m[X] == 0)
            return -1;

        return m[X];
	}
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}