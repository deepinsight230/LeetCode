class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1&&k%2==1) return -1;
        int mx=-1;
        for(int i=0;i<n&&i<k-1;i++) mx=max(nums[i], mx);
        if(n>=k) mx=max(mx, nums[k]);
        return mx;
    }
};