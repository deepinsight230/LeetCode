class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            int last=lis.back();
            if(nums[i]>last) lis.push_back(nums[i]);
            else{
                int idx=lower_bound(lis.begin(), lis.end(), nums[i])-lis.begin();
                lis[idx]=nums[i];
            }
        }
        return lis.size();
    }
};