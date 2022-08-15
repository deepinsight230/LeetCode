class Solution {
public:
    void helper(int i, int j, int prev, vector<vector<int>> &vis, vector<vector<int>>& grid, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j]) return;
        if(grid[i][j]<prev) return;
        vis[i][j]=1;
        helper(i+1, j, grid[i][j], vis, grid, m, n);
        helper(i-1, j, grid[i][j], vis, grid, m, n);
        helper(i, j+1, grid[i][j], vis, grid, m, n);
        helper(i, j-1, grid[i][j], vis, grid, m, n);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> ans, vis(m, vector<int> (n, 0));
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i=0;i<n;i++){ 
            helper(0, i, INT_MIN, vis, grid, m, n); //first row
            helper(m-1, i, INT_MIN, visited, grid, m, n); //last row
        }
        for(int i=0;i<m;i++){ 
            helper(i, 0, INT_MIN, vis, grid, m, n); //first column
            helper(i, n-1, INT_MIN, visited, grid, m, n); //last column
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] && visited[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};