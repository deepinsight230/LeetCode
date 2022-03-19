class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n+1, 0);
        dp[1]=1;
        for(int i=2;i<n+1;i++){
            long long mn=LLONG_MAX;
            bool f1=false, f2=false, f3=false;
            for(int j=1;j<i;j++){
                if(dp[j]*2>dp[i-1]){
                    mn=min(mn, dp[j]*2);
                    f1=true;
                }
                if(dp[j]*3>dp[i-1]){
                    mn=min(mn, dp[j]*3);
                    f2=true;
                }
                if(dp[j]*5>dp[i-1]){
                    mn=min(mn, dp[j]*5);
                    f3=true;
                }
                if(f1&&f2&&f3) break;
            }
            dp[i]=mn;
        }
        return dp[n];
    }
};