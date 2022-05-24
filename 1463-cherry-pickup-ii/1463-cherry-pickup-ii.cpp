class Solution {
public:
    int dp[75][75][75];
    int helper(int i, int j1, int j2, vector<vector<int>>& grid){
        int m=grid.size();
        if(i==m) return 0;
        if(j1<0||j2<0||j1>=grid[0].size()||j2>=grid[0].size()) return INT_MIN;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int cherries=0;
        if(j1==j2) cherries+=grid[i][j1];
        else cherries+=grid[i][j1]+grid[i][j2];
        int temp=INT_MIN;
        for(int k=-1;k<=1;k++){
            for(int j=-1;j<=1;j++){
                temp=max(temp, helper(i+1, j1+k, j2+j, grid));
            }
        }
        cherries+=temp;
        return dp[i][j1][j2]=cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid[0].size();
        memset(dp, -1, sizeof(dp));
        return max(0, helper(0, 0, n-1, grid));
    }
};