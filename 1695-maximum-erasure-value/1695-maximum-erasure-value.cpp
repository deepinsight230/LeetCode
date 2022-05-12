class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0, sum=0;
        unordered_map<int, int> mp;
        int i=0, j=0, n=nums.size();
        while(j<n){
            mp[nums[j]]++;
            sum+=nums[j];
            if(mp[nums[j]]==1) j++;
            else{
                while(mp[nums[j]]>1){
                    sum-=nums[i];
                    mp[nums[i]]--;
                    i++;
                }
                j++;
            }
            ans=max(ans, sum);
        }
        return ans;
    }
};