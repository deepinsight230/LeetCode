class Solution {
public:
    void helper(int idx, vector<int> &ds, vector<vector<int>> &ans, int n, int k){
        if(ds.size()==k){
            if(n==0) ans.push_back(ds);
            return;
        }
        if(idx>9) return;
        if(idx<=n){
            ds.push_back(idx);
            helper(idx+1, ds, ans, n-idx, k);
            ds.pop_back();
        }
        helper(idx+1, ds, ans, n, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(1, ds, ans, n, k);
        return ans;
    }
};