class Solution {
public:
    int helper(vector<int> &nums, int l, int r){
        int inc=0, exc=0;
        for(int i=l;i<=r;i++){
            int temp=max(inc, nums[i]+exc);
            exc=inc;
            inc=temp;
        }
        return inc;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }
};