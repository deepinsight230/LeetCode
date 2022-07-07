class Solution {
public:
    bool helper(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>> &dp){
        if(i==s1.size()&&j==s2.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<s1.size()&&s1[i]==s3[k]&&j<s2.size()&&s2[j]==s3[k]){
            return dp[i][j]=helper(i+1, j, k+1, s1, s2, s3, dp)||helper(i, j+1, k+1, s1, s2, s3, dp);
        }
        else if(i<s1.size()&&s1[i]==s3[k]) return dp[i][j]=helper(i+1, j, k+1, s1, s2, s3, dp);
        else if(j<s2.size()&&s2[j]==s3[k]) return dp[i][j]=helper(i, j+1, k+1, s1, s2, s3, dp);
        else return dp[i][j]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(), n=s2.size(), o=s3.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        if(m+n != o) return false;
        return helper(0, 0, 0, s1, s2, s3, dp);
    }
};