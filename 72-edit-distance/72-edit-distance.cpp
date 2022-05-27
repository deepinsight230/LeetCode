class Solution {
public:
    int helper(int m, int n, string str1, string str2, vector<vector<int>> &dp){
        if(m<0) return n+1;
        if(n<0) return m+1;
        if(dp[m][n]!=-1) return dp[m][n];
        if(str1[m]==str2[n]){
            return dp[m][n]=helper(m-1, n-1, str1, str2, dp);
        }
        else{
            int insert=helper(m, n-1, str1, str2, dp);
            int replace=helper(m-1, n-1, str1, str2, dp);
            int del=helper(m-1, n, str1, str2, dp);
            return dp[m][n]=1+min(insert, min(replace, del));
        }
    }
    int minDistance(string str1, string str2) {
        int m=str1.size(), n=str2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(m-1, n-1, str1, str2, dp);
    }
};