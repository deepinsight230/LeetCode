class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1;i<n+1;i++){
            int mn=INT_MAX;
            for(int j=1;j<=sqrt(i);j++){
                mn=min(mn, dp[i-(j*j)]);
            }
            dp[i]=mn+1;
        }
        return dp[n];
    }
};