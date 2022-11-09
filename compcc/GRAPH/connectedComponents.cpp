#include<bits/stdc++.h>
using namespace std;


class Solution {

    vector<vector<bool>> vis;
    
    int x[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
        
public:
    bool isSafe(int row, int col, vector<vector<char>>& grid) {
       
        int ROW = grid.size();      // ye height/row of grid deta
        int COL = grid[0].size();   // ye lenght/col of grid deta.
        
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL)
                && (grid[row][col] == '1') && (vis[row][col] == false);
    }
    
    void dfs(int row, int col, vector<vector<char>>& grid) {

        vis[row][col] = true;
        
        for (int i = 0; i < 8; i++) {
            if (isSafe(row+x[i], col+y[i], grid)) {
                dfs(row+x[i], col+y[i], grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        
        // cout << "numIslands:: " << row << " " << col << "\n";
        
        vis.resize(row);
        for (int i = 0; i < row; ++i) vis[i].resize(col);
        
        // main funda isme ye hai ki,
        // iska jo main dfs calling func hai,
        // wo every node visit krega,
        // and dfsutil wala baccha every edge, jo connected hain, unme jayega.
        // to ye basically do func bante.
        // isliye uske dfsutil me 8 edges bante, wo pata krna tha, baas.

        int connectedComp = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((grid[i][j] == '1') && (vis[i][j] == false)) {
                    dfs(i, j, grid);
                    connectedComp++;
                }
            }
        }
        return connectedComp;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  