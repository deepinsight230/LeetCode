class Solution {
public:
    int subsets(int idx, int xoR, vector<int> &nums, int n){
        if(idx == n){
            return xoR;
        }
        int inc=subsets(idx+1, xoR^nums[idx], nums, n);
        int exc=subsets(idx+1, xoR, nums, n);
        return inc+exc;
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        return subsets(0, 0, nums, n);
    }
};