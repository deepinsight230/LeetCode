class Solution {
public:
    int helper(int i, vector<int> nums, int sum, int target, int tsum, vector<vector<int>> &dp){
        if(i==nums.size()){
            int othersum=tsum-sum;
            if((sum-othersum)==target) return 1;
            else return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int pick=helper(i+1, nums, sum+nums[i], target, tsum, dp);
        int notpick=helper(i+1, nums, sum, target, tsum, dp);
        return dp[i][sum]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum=0;
        for(int i: nums) tsum+=i;
        vector<vector<int>> dp(nums.size(), vector<int> (tsum+1, -1));
        return helper(0, nums, 0, target, tsum, dp);
    }
};