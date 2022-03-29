class Solution {
public:
    void helper(string &ds, vector<string> &ans, int n, int open, int close){
        if(ds.size()==(2*n)){
            ans.push_back(ds);
            return;
        }
        if(open<n){
            ds+='(';
            helper(ds, ans, n, open+1, close);
            ds.pop_back();
        }
        if(close<open){
            ds+=')';
            helper(ds, ans, n, open, close+1);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds="";
        helper(ds, ans, n, 0, 0);
        return ans;
    }
};