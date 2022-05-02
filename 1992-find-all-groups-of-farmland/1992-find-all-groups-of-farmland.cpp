class Solution {
public:
    void helper(vector<vector<int>>& land, int i, int j, int m, int n, pair<int, int> &pr){
        if(i<0||i>=m||j<0||j>=n||land[i][j]==0) {
            return;
        }
        land[i][j]=0;
        if(i+1>=m||j+1>=n||land[i+1][j]==0||land[i][j+1]==0){
            if(i>pr.first||j>pr.second){
                pr.first=i;
                pr.second=j;
            }
        }
        helper(land, i, j+1, m, n, pr);
        helper(land, i+1, j, m, n, pr);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size(), n=land[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    vector<int> ds;
                    ds.push_back(i);
                    ds.push_back(j);
                    pair<int, int> pr;
                    helper(land, i, j, m, n, pr);
                    ds.push_back(pr.first);
                    ds.push_back(pr.second);
                    ans.push_back(ds);
                }
            }
        }
        return ans;
    }
};