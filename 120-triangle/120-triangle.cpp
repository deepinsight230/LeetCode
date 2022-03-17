class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp;
        for(int i=1;i<=n;i++){
            vector<int> row(i, 0);
            dp.push_back(row);
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                if(i==(n-1)) dp[i][j]=triangle[i][j];
                else dp[i][j]=min(dp[i+1][j], dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};