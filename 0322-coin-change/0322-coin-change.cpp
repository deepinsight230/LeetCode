class Solution {
public:
    int helper(int i, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(i >= coins.size() || amount<0) return INT_MAX-1;
        if(amount == 0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=1+helper(i, coins, amount-coins[i], dp);
        int nottake=helper(i+1, coins, amount, dp);
        return dp[i][amount]=min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans=helper(0, coins, amount, dp);
        return (ans==INT_MAX-1)?-1:ans;
    }
};