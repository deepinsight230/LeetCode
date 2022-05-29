class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 1);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int temp=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    temp=max(temp, dp[j]);
                }
            }
            dp[i]+=temp;
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};