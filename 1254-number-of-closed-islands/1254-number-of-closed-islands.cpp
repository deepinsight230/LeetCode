class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        if(grid[i][j] == 1 || vis[i][j] == 1) return true;
        vis[i][j]=1;
        bool t1=dfs(i+1, j, grid, vis, m, n);
        bool t2=dfs(i, j+1, grid, vis, m, n);
        bool t3=dfs(i-1, j, grid, vis, m, n);
        bool t4=dfs(i, j-1, grid, vis, m, n);
        return t1&t2&t3&t4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    if(dfs(i, j, grid, vis, m, n)) ans++;
                }
            }
        }
        return ans;
    }
};