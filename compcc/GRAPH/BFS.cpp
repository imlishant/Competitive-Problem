#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> visited;
    vector<int> ans;
public:
    void BFSUtil(int v, vector<int> adj[]) {
	    queue<int> q;
        q.push(v);
        visited[v] = true;

        vector<int>::iterator it;

        while (q.empty() == false) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (it = adj[u].begin(); it != adj[u].end(); ++it) {
                if (visited[*it] == false) {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
    }

	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    // Code here
        visited.clear();
        visited.resize(V);

        ans.clear();

        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                BFSUtil(i, adj);
            }
        }
        return ans;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}