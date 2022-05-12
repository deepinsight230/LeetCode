class Solution {
public:
    void helper(int idx, set<vector<int>> &s, vector<int> &nums){
        if(idx==nums.size()-1){
            s.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i], nums[idx]);
            helper(idx+1, s, nums);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        helper(0, s, nums);
        for(auto i: s){
            ans.push_back(i);
        }
        return ans;
    }
};