class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowBegin, colBegin, rowEnd, colEnd;
        rowBegin=0, colBegin=0, rowEnd=matrix.size()-1, colEnd=matrix[0].size()-1;
        while (rowBegin<=rowEnd&&colBegin<=colEnd){
            for(int j=colBegin;j<=colEnd;j++)
                ans.push_back(matrix[rowBegin][j]);
            rowBegin++;
            for(int i=rowBegin;i<=rowEnd;i++)
                ans.push_back(matrix[i][colEnd]);
            colEnd--;
            for(int j=colEnd;rowBegin<=rowEnd&&j>=colBegin;j--)
                ans.push_back(matrix[rowEnd][j]);
            rowEnd--;
            for(int i=rowEnd;colBegin<=colEnd&&i>=rowBegin;i--)
                ans.push_back(matrix[i][colBegin]);
            colBegin++;
        }
        return ans;
    }
};