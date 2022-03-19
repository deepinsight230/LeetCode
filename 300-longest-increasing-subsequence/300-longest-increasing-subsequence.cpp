class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), ans=INT_MIN;
        vector<int> dp(n, 1);
        for(int i=0;i<n;i++){
            int mx=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    mx=max(mx, dp[j]);
            }
            dp[i]=mx+1;
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};