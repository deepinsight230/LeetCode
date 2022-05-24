class Solution {
public:
    int helper(int i, bool bought, vector<int> &prices, vector<vector<int>> &dp){
        if(i>=prices.size()) return 0;
        if(dp[i][bought]!=-1) return dp[i][bought];
        if(bought==false){
            int buy=-prices[i]+helper(i+1, true, prices, dp);
            int notbuy=helper(i+1, false, prices, dp);
            return dp[i][bought]=max(buy, notbuy);
        }
        else{
            int sell=prices[i]+helper(i+2, false, prices, dp);
            int notsell=helper(i+1, true, prices, dp);
            return dp[i][bought]=max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return helper(0, false, prices, dp);
    }
};