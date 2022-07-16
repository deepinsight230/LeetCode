class Solution {
public:
    int dp[51][51][51];
    int mod=1e9+7;
    int helper(int i, int j, int moves, int m, int n){
        if(moves<0) return 0;
        if(i<0||j<0||i>=m||j>=n) return 1;
        if(dp[i][j][moves]!=-1) return dp[i][j][moves];
        int ans=0;
        ans=(ans+helper(i+1, j, moves-1, m, n))%mod;
        ans=(ans+helper(i-1, j, moves-1, m, n))%mod;
        ans=(ans+helper(i, j+1, moves-1, m, n))%mod;
        ans=(ans+helper(i, j-1, moves-1, m, n))%mod;
        return dp[i][j][moves]=(ans%mod);
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(startRow, startColumn, maxMove, m, n);
    }
};