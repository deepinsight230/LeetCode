class Solution {
public:
    void helper(int i, int j, vector<vector<int>>& grid, int m, int n, int open, int &ans){
        
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==-1) return;
        if(grid[i][j]==2){
            if(open==-1) ans++;
            return;
        }
        grid[i][j]=-1;
        helper(i+1, j, grid, m, n, open-1, ans);
        helper(i, j-1, grid, m, n, open-1, ans);
        helper(i, j+1, grid, m, n, open-1, ans);
        helper(i-1, j, grid, m, n, open-1, ans);
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int si, sj, open=0;
        int m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) si=i, sj=j;
                // else if(grid[i][j]==2) ei=i, ej=j;
                else if(grid[i][j]==0) open++;
            }
        }
        int ans=0;
        helper(si, sj, grid, m, n, open, ans);
        return ans;
    }
};