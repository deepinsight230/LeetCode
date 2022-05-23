class Solution {
public:
    int helper(int i, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(i==nums.size()){
            if(sum==0) return 0;
            else return INT_MIN;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int pick=nums[i]+helper(i+1, (sum+nums[i])%3, nums, dp);
        int notpick=helper(i+1, sum, nums, dp);
        return dp[i][sum]=max(pick, notpick);
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (3, -1));
        return helper(0, 0, nums, dp);
    }
};