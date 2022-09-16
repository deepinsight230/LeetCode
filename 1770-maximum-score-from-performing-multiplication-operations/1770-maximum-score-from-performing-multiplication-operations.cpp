class Solution {
public:
    int helper(int l, int r, int i, vector<int>& nums, vector<int>& mult, vector<vector<int>> &dp, int m){
        if(i == m){
            return 0;
        }
        if(dp[l][r] != INT_MIN) return dp[l][r];
        int temp1=nums[l] * mult[i] + helper(l+1, r, i+1, nums, mult, dp, m);
        int temp2=nums[r] * mult[i] + helper(l, r-1, i+1, nums, mult, dp, m);
        return dp[l][r] = max(temp1, temp2);
    }
    int maximumScore(vector<int>& num, vector<int>& multipliers) {
        vector<int> nums;
        int nn=num.size(), m=multipliers.size();
        if(nn > 2*m){
            for(int i=0;i<m;i++){
                nums.push_back(num[i]);
            }
            for(int i=m-1;i>=0;i--){
                nums.push_back(num[nn-1-i]);
            }
        }
        else nums = num;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MIN));
        return helper(0, n-1, 0, nums, multipliers, dp, m);
    }
};