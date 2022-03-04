class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j){
        if(i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0') return;
        grid[i][j]='0';
        helper(grid, i+1, j);
        helper(grid, i-1, j);
        helper(grid, i, j+1);
        helper(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1') ans++, helper(grid, i, j);
            }
        }
        return ans;
    }
};