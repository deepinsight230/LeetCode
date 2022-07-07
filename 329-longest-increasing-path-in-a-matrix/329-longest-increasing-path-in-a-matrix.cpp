class Solution {
public:
    int helper(int i, int j, int prev, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()) return 0;
        if(matrix[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int t1=helper(i+1, j, matrix[i][j], matrix, dp);
        int t2=helper(i, j+1, matrix[i][j], matrix, dp);
        int t3=helper(i-1, j, matrix[i][j], matrix, dp);
        int t4=helper(i, j-1, matrix[i][j], matrix, dp);
        return dp[i][j]=max({t1, t2, t3, t4})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans, helper(i, j, -1, matrix, dp));
            }
        }
        return ans;
    }
};