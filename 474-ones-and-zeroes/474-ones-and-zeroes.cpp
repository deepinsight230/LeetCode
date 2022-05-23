class Solution {
public:
    int helper(int i, vector<pair<int, int>> &arr, int m, int n, vector<vector<vector<int>>> &dp){
        if(i==arr.size()||(m+n)<=0) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int remzeroes=m-arr[i].first, remones=n-arr[i].second;
        if(remzeroes>=0&&remones>=0){
            int pick=1+helper(i+1, arr, remzeroes, remones, dp);
            int notpick=helper(i+1, arr, m, n, dp);
            return dp[i][m][n]=max(pick, notpick);
        }
        else{
            int notpick=helper(i+1, arr, m, n, dp);
            return dp[i][m][n]=notpick;
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> arr;
        for(string s: strs){
            int ones=0, zeroes=0;
            for(char ch: s){
                if(ch=='1') ones++;
                else zeroes++;
            }
            arr.push_back({zeroes, ones});
        }
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        return helper(0, arr, m, n, dp);
    }
};