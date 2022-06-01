class Solution {
public:
    int atmostk(vector<int> &nums, int k){
        unordered_map<int, int> mp;
        int i=0, j=0, n=nums.size();
        int ans=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp.size()<=k){
                ans+=(j-i+1);
                j++;
            }
            else{
                while(mp.size()>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }
                ans+=(j-i+1);
                j++;
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (atmostk(nums, k)-atmostk(nums, k-1));
    }
};