class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& vis, vector<vector<int>>& grid){
        if(i<0||j<0||i>=m||j>=n) return 0;
        if(grid[i][j]==0 || vis[i][j]==1) return 0;
        vis[i][j]=1;
        int t1=dfs(i+1, j, m, n, vis, grid);
        int t2=dfs(i-1, j, m, n, vis, grid);
        int t3=dfs(i, j+1, m, n, vis, grid);
        int t4=dfs(i, j-1, m, n, vis, grid);
        return (t1+t2+t3+t4+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=INT_MIN;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans, dfs(i, j, m, n, vis, grid));
            }
        }
        return ans;
    }
};