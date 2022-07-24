class Solution {
public:
    int helper(int i, bool pos, vector<int> &nums, int n, vector<vector<int>> &dp){
        if(i== n-1) return 0;
        if(dp[i][pos]!=-1) return dp[i][pos];
        int take=0, nottake=0;
        if(pos){
            if(nums[i+1]>nums[i]) take=1+helper(i+1, false, nums, n, dp);
            else nottake=helper(i+1, true, nums, n, dp);
        }
        else{
            if(nums[i+1]<nums[i]) take=1+helper(i+1, true, nums, n, dp);
            else nottake=helper(i+1, false, nums, n, dp);
        }
        return dp[i][pos]=max(take, nottake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        int t1=helper(0, true, nums, n, dp);
        fill(dp.begin(), dp.end(), vector<int> (2, -1));
        int t2=helper(0, false, nums, n, dp);
        return max(t1, t2)+1;
    }
};