class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int csum=0, n=nums.size();
        int ans=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1) csum++;
            if(mp.find(csum-k)!=mp.end()){
                ans+=mp[csum-k];
            }
            mp[csum]++;
        }
        return ans;
    }
};