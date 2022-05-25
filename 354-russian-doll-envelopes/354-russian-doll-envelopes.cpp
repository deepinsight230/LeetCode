class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0])return a[1]>b[1];
        else return  a[0]<b[0] ;
    }
    int maxEnvelopes(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin() , nums.end() , comp);
        vector<int>dp;
        for(int i=0;i<n;i++){
            int x = lower_bound(dp.begin(),dp.end() , nums[i][1]) - dp.begin();
            if(x == dp.size())dp.push_back(nums[i][1]);
            else dp[x]=nums[i][1];
        }
        return dp.size();
    }
};