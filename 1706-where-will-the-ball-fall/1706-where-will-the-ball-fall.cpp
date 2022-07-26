class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(n, -1);
        for(int i=0;i<n;i++){
            int cpos=i, npos=i;
            for(int j=0;j<m;j++){
                npos=cpos+grid[j][cpos];
                if(npos<0 || npos>=n){
                    npos=-1; break;
                }
                else if(grid[j][npos]!=grid[j][cpos]){
                    npos=-1; break;
                }
                cpos=npos;
            }
            ans[i]=npos;
        }
        return ans;
    }
};