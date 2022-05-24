class Solution {
public:
    int dp[51][51][51][51];
    int helper(int i1, int j1, int i2, int j2, vector<vector<int>>& grid){
        int n=grid.size();
        if(i1>=n||i2>=n||j1>=n||j2>=n|| grid[i1][j1]==-1 || grid[i2][j2]==-1) return INT_MIN;
        if((i1==(n-1))&&(j1==(n-1))) return grid[i1][j1];
        if(dp[i1][i2][j1][j2]!=-1) return dp[i1][i2][j1][j2];
        int cherries;
        if(i1==i2 && j1==j2) cherries=grid[i1][j1];
        else cherries=grid[i1][j1]+grid[i2][j2];
        cherries+=max(max(helper(i1+1, j1, i2+1, j2, grid), helper(i1+1, j1, i2, j2+1, grid)), max(helper(i1, j1+1, i2+1, j2, grid), helper(i1, j1+1, i2, j2+1, grid)));
        return dp[i1][i2][j1][j2]=cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return max(0, helper(0, 0, 0, 0, grid));
    }
};