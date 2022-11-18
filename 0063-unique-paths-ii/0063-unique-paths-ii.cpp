class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int right=helper(i, j+1, grid, dp, m, n);
        int down=helper(i+1, j, grid, dp, m, n);
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(0, 0, grid, dp, m, n);
    }
};