class Solution {
public:
    int lcs(int m, int n, string &s, string &t, vector<vector<int>> &dp){
        if(m<0) return 0;
        if(n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m]==t[n]){
            return dp[m][n]=1+lcs(m-1, n-1, s, t, dp);
        }
        else{
            return dp[m][n]=max(lcs(m-1, n, s, t, dp), lcs(m, n-1, s, t, dp));
        }
    }
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(), t.end());
        int n=s.size();
        // cout<<n;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int lcp=lcs(n-1, n-1, s, t, dp);
        return (n-lcp);
    }
};