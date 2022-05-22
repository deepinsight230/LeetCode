class Solution {
public:
    int helper(int day, bool bought, int k, vector<int> &prices, vector<vector<int>> &dp){
        if(k==0||day==prices.size()) return 0;
        if(dp[day][bought]!=-1) return dp[day][bought];
        if(bought==false){
            int buy=-prices[day]+helper(day+1, true, k, prices, dp);
            int notbuy=helper(day+1, false, k, prices, dp);
            return dp[day][bought]=max(buy, notbuy);
        }
        else{
            int sell=prices[day]+helper(day+1, false, k-1, prices, dp);
            int notsell=helper(day+1, true, k, prices, dp);
            return dp[day][bought]=max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return helper(0, false, 1, prices, dp);
    }
};