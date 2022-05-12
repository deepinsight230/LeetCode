class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> res(m, vector<int> (n, 0));
        res[0][0]=matrix[0][0];
        for(int i=1;i<n;i++) res[0][i]=res[0][i-1]^matrix[0][i];
        for(int i=1;i<m;i++) res[i][0]=res[i-1][0]^matrix[i][0];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                res[i][j]=res[i-1][j-1]^res[i-1][j]^res[i][j-1]^matrix[i][j];
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pq.push(res[i][j]);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};