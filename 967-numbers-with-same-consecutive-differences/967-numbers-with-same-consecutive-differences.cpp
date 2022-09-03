class Solution {
public:
    void helper(string s, vector<int> &ans, int n, int k){
        if(s.size() == n){
            ans.push_back(stoi(s));
            return;
        }
        int next1=(s.back()-'0')+k;
        if(next1<10){
            helper(s+to_string(next1), ans, n, k);
        }
        int next2=(s.back()-'0')-k;
        if(next2>=0 && next2!=next1){
            helper(s+to_string(next2), ans, n, k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            string s=to_string(i);
            helper(s, ans, n, k);
        }
        return ans;
    }
};