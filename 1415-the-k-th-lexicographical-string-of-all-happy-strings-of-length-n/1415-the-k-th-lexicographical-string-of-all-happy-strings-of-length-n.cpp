class Solution {
public:
    void helper(string &ans, string ds, string &str, int n, int &k){
        if(ds.size()==n){
            k--;
            if(k==0) ans=ds;
            return;
        }
        for(int i=0;i<str.size();i++){
            if(ds.empty()||ds[ds.size()-1]!=str[i]) helper(ans, ds+str[i], str, n, k);
        }
    }
    string getHappyString(int n, int k) {
        string ans="", str="abc";
        helper(ans, "", str, n, k);
        return ans;
    }
};