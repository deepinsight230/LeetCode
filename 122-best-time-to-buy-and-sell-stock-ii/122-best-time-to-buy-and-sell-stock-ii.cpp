class Solution {
public:
    int helper(int i, bool bought, vector<int> &prices, int n, vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][bought]!=-1) return dp[i][bought];
        if(bought){
            return dp[i][bought]=max(helper(i+1, true, prices, n, dp), prices[i]+helper(i+1, false, prices, n, dp));
        }
        else{
            return dp[i][bought]=max(helper(i+1, false, prices, n, dp), -prices[i]+helper(i+1, true, prices, n, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return helper(0, false, prices, n, dp);
    }
};