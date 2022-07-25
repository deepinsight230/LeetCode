class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int psum=0, ans=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
            ans+=mp[psum-k];
            mp[psum]++;
        }
        return ans;
    }
};