class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int l2=0, l3=0, l5=0;
        for(int i=1;i<n;i++){
            dp[i]=min(dp[l2]*2, min(dp[l3]*3, dp[l5]*5));
            if(dp[i]==dp[l2]*2) l2++;
            else if(dp[i]==dp[l3]*3) l3++;
            else if(dp[i]==dp[l5]*5) l5++;
            // cout<<i<<" "<<dp[i]<<" "<<l2<<" "<<l3<<" "<<l5<<endl;
            if(dp[i]<=dp[i-1]) i--;
        }
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        return dp[n-1];
    }
};