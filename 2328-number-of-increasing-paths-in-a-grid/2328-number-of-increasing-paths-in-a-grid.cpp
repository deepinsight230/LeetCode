#define mod 1000000007;
class Solution {
public:
    int helper(int i, int j, int prev, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return 0;
        if(grid[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int t1=helper(i, j+1, grid[i][j], dp, grid);
        int t2=helper(i+1, j, grid[i][j], dp, grid);
        int t3=helper(i-1, j, grid[i][j], dp, grid);
        int t4=helper(i, j-1, grid[i][j], dp, grid);
        return dp[i][j]=(1+t1+t2+t3+t4)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=(ans+helper(i, j, -1, dp, grid))%mod;
            }
        }
        return ans;
    }
};