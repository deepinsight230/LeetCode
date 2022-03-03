class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n, 0));
        int cnt=1;
        int rowBegin=0, rowEnd=n-1, colBegin=0, colEnd=n-1;
        while(rowBegin<=rowEnd&&colBegin<=colEnd){
            for(int i=colBegin;i<=colEnd;i++)
                res[rowBegin][i]=cnt++;
            rowBegin++;
            for(int i=rowBegin;i<=rowEnd;i++)
                res[i][colEnd]=cnt++;
            colEnd--;
            for(int i=colEnd;i>=colBegin;i--)
                res[rowEnd][i]=cnt++;
            rowEnd--;
            for(int i=rowEnd;i>=rowBegin;i--)
                res[i][colBegin]=cnt++;
            colBegin++;
        }
        vector<vector<int>> ans;
        for(auto it: res){
            ans.push_back(it);
        }
        return ans;
    }
};