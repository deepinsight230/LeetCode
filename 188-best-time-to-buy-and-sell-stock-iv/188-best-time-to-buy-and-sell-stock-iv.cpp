class Solution {
public:
    int helper(int day, bool bought, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(k<=0||day>=prices.size()) return 0;
        if(dp[day][bought][k]!=-1) return dp[day][bought][k];
        if(bought==false){
            int buy=-prices[day]+helper(day+1, true, k, prices, dp);
            int notbuy=helper(day+1, false, k, prices, dp);
            return dp[day][bought][k]=max(buy, notbuy);
        }
        else{
            int sell=prices[day]+helper(day+1, false, k-1, prices, dp);
            int notsell=helper(day+1, true, k, prices, dp);
            return dp[day][bought][k]=max(sell, notsell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // cout<<n;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return helper(0, false, k, prices, dp);
    }
};