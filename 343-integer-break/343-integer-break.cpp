class Solution {
public:
    int helper(int n, int num, vector<int> &dp){
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int temp;
        if(n==num) temp=0;
        else temp=n;
        for(int i=1;i<n;i++){
            temp=max(temp, helper(i, num, dp)*helper(n-i, num, dp));
        }
        return dp[n]=temp;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, n, dp);
    }
};