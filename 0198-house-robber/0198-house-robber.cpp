class Solution {
public:
    int helper(int i, vector<int> &nums, vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int rob=nums[i]+helper(i+2, nums, dp);
        int notrob=helper(i+1, nums, dp);
        return dp[i]=max(rob, notrob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, dp);
    }
};