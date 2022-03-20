class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        for(int i=2;i<n+1;i++){
            int temp=0;
            for(int j=0;j<i;j++){
                temp+=dp[j]*dp[i-j-1];
            }
            dp[i]=temp;
        }
        // for(int i=0;i<n+1;i++) cout<<dp[i]<<" ";
        return dp[n];
    }
};