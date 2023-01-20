class Solution {
public:
    int subsets(int idx, int xoR, vector<int> &nums, int n){
        if(idx == n){
            return xoR;
        }
        xoR=xoR^nums[idx];
        int inc=subsets(idx+1, xoR, nums, n);
        xoR=xoR^nums[idx];
        int exc=subsets(idx+1, xoR, nums, n);
        return inc+exc;
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        return subsets(0, 0, nums, n);
    }
};