class Solution {
public:
    int helper(int i, int copied, int n, vector<vector<int>> &dp){
        if(i==n) return 0;
        if(i>n) return 10000;
        if(dp[i][copied]!=-1) return dp[i][copied];
        if(copied==0){
            int copy=1+helper(i, i, n, dp);
            return dp[i][copied]=copy;
        }
        else{
            if(i!=copied){
                int copy=1+helper(i, i, n, dp);
                int paste=1+helper(i+copied, copied, n, dp);
                return dp[i][copied]=min(copy, paste);
            }
            else{
                int paste=1+helper(i+copied, copied, n, dp);
                return dp[i][copied]=paste;
            }
        }
    }
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n, -1));
        return max(0, helper(1, 0, n, dp));
    }
};