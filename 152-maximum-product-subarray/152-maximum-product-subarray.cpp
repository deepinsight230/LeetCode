class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn=nums[0], mx=nums[0], ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=mx;
            mx=max(max(nums[i]*mx, nums[i]*mn), nums[i]);
            mn=min(min(nums[i]*temp, nums[i]*mn), nums[i]);
            ans=max(ans, mx);
        }
        return ans;
    }
};