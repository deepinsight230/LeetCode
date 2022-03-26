class Solution {
public:
    void helper(int &curr, int &ans, int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis, int m, int n){
        if(row<0||row>=m||col<0||col>=n||vis[row][col]||grid[row][col]==0){
            
            return;
        }
        vis[row][col]=true;
        curr+=grid[row][col];
        helper(curr, ans, row+1, col, grid, vis, m, n);
        helper(curr, ans, row, col+1, grid, vis, m, n);
        helper(curr, ans, row-1, col, grid, vis, m, n);
        helper(curr, ans, row, col-1, grid, vis, m, n);
        ans=max(ans, curr);
        curr-=grid[row][col];
        vis[row][col]=false;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        int ans=0, curr=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    helper(curr, ans, i, j, grid, vis, m, n);
                }
            }
        }
        return ans;
    }
};