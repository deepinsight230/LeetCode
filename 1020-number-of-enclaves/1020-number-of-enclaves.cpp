class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] == 1 || grid[i][j] == 0) return;
        vis[i][j]=1;
        grid[i][j]=2;
        dfs(i+1, j, grid, vis, m, n);
        dfs(i, j+1, grid, vis, m, n);
        dfs(i-1, j, grid, vis, m, n);
        dfs(i, j-1, grid, vis, m, n);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1) dfs(i, j, grid, vis, m, n);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) grid[i][j]=1;
                else if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};