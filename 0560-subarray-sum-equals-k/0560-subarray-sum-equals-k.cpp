class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]=1;
        int ans=0, cum_sum=0;
        for(int i=0;i<nums.size();i++){
            cum_sum+=nums[i];
            ans+=mp[cum_sum-k];
            mp[cum_sum]++;
        }
        return ans;
    }
};