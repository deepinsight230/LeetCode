class Solution {
public:
    void helper(int idx, vector<int> &ds, set<vector<int>> &ans, vector<int> nums){
        if(idx==nums.size()){
            if(ds.size()>=2){
                ans.insert(ds);
            }
            return;
        }
        if(ds.empty()||(ds[ds.size()-1]<=nums[idx])){
            ds.push_back(nums[idx]);
            helper(idx+1, ds, ans, nums);
            ds.pop_back();
        }
        helper(idx+1, ds, ans, nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> ans;
        vector<int> ds;
        helper(0, ds, ans, nums);
        for(auto i: ans)
            res.push_back(i);
        return res;
    }
};