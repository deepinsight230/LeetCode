class Solution {
public:
    bool helper(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(i==nums.size()){
            if(target==0) return true;
            else return false;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        if(nums[i]<=target){
            bool pick=helper(i+1, target-nums[i], nums, dp);
            bool notpick=helper(i+1, target, nums, dp);
            return dp[i][target]=(pick||notpick);
        }
        else{
            bool notpick=helper(i+1, target, nums, dp);
            return dp[i][target]=notpick;
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i: nums) sum+=i;
        if(sum%2==1) return false;
        vector<vector<int>> dp(nums.size()+1, vector<int> ((sum/2)+1, -1));
        return helper(0, (sum/2), nums, dp);
    }
};