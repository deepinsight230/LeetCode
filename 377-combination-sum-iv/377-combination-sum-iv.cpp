class Solution {
public:
    int helper(int i, vector<int> &nums, int target, vector<int> &dp){
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int ind=0;ind<nums.size();ind++){
            ans+=helper(ind, nums, target-nums[ind], dp);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return helper(0, nums, target, dp);
    }
};