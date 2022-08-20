class Solution {
public:
    int dp[502];
    int helper(int i, vector<int>& arr, int k, int n){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN, len=0, mx=INT_MIN;
        for(int ind=i;ind<min(i+k, n);ind++){
            len++;
            mx=max(mx, arr[ind]);
            int sum=(len*mx)+helper(ind+1, arr, k, n);
            ans=max(ans, sum);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, arr, k, n);
    }
};