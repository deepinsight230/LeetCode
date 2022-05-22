class Solution {
public:
    int helper(int house, vector<int> &nums, vector<int> &dp){
        if(house>=nums.size()) return 0;
        if(dp[house]!=-1) return dp[house];
        int rob=nums[house]+helper(house+2, nums, dp);
        int notrob=helper(house+1, nums, dp);
        return dp[house]=max(rob, notrob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, dp);
    }
};