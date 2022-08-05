class Solution {
public:
    void helper(int i, vector<int> &ds, vector<vector<int>> &ans, int k, int n){
        if(ds.size()==k){
            if(n==0) ans.push_back(ds);
            return;
        }
        
        for(int ind=i;ind<=9;ind++){
            if(n>0){
                ds.push_back(ind);
                helper(ind+1, ds, ans, k, n-ind);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        helper(1, ds, ans, k, n);
        return ans;
    }
};