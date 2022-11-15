class Solution {
public:
    int dfs(int i, int j, int &ans, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] == 1 || grid[i][j] == 0) return 0;
        vis[i][j]=1;
        int t1=dfs(i+1, j, ans, grid, vis, m, n);
        int t2=dfs(i, j+1, ans, grid, vis, m, n);
        int t3=dfs(i-1, j, ans, grid, vis, m, n);
        int t4=dfs(i, j-1, ans, grid, vis, m, n);
        ans=max(ans, t1+t2+t3+t4+1);
        return t1+t2+t3+t4+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) dfs(i, j, ans, grid, vis, m, n);
            }
        }
        return ans;
    }
};