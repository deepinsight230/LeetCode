class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(), ans=0, maxlen=1;
        vector<pair<int, int>> dp(n, {1, 1});
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j].first+1>dp[i].first){
                        dp[i].first=dp[j].first+1;
                        dp[i].second=dp[j].second;
                    }
                    else if(dp[j].first+1==dp[i].first)
                        dp[i].second+=dp[j].second;
                }
            }
            maxlen=max(maxlen, dp[i].first);
        }
        for(int i=0;i<n;i++){
            if(dp[i].first==maxlen) ans+=dp[i].second;
            cout<<dp[i].first<<" "<<dp[i].second<<endl;
        }
        return ans;
    }
};