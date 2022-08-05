class Solution {
public:
    void helper(int i, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums, int target){
        if(target<0) return;
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int ind=i;ind<nums.size();ind++){
            ds.push_back(nums[ind]);
            helper(ind, ds, ans, nums, target-nums[ind]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, ds, ans, candidates, target);
        return ans;
    }
};