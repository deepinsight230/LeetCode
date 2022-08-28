class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, 0));
        for(int i=0;i<m;i++){
            int r=i, c=0;
            vector<int> arr;
            while(r<m && c<n){
                arr.push_back(mat[r++][c++]);
            }
            sort(arr.begin(), arr.end());
            r=i, c=0;
            int k=0;
            while(r<m && c<n){
                ans[r++][c++]=arr[k++];
            }
        }
        for(int j=1;j<n;j++){
            int r=0, c=j;
            vector<int> arr;
            while(r<m && c<n){
                arr.push_back(mat[r++][c++]);
            }
            sort(arr.begin(), arr.end());
            r=0, c=j;
            int k=0;
            while(r<m && c<n){
                ans[r++][c++]=arr[k++];
            }
        }
        return ans;
    }
};