class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n){
        if(i<0 || j<0 || i>=m ||j>=n || vis[i][j] == 1 || grid[i][j] == 'X') return;
        vis[i][j]=1;
        grid[i][j]='Y';
        dfs(i+1, j, grid, vis, m, n);
        dfs(i, j+1, grid, vis, m, n);
        dfs(i-1, j, grid, vis, m, n);
        dfs(i, j-1, grid, vis, m, n);
    }
    void solve(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int i=0;i<m;i++){
            dfs(i, 0, grid, vis, m, n);
            dfs(i, n-1, grid, vis, m, n);
        }
        for(int j=0;j<n;j++){
            dfs(0, j, grid, vis, m, n);
            dfs(m-1, j, grid, vis, m, n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 'Y') grid[i][j]='O';
                else grid[i][j]='X';
            }
        }
    }
};