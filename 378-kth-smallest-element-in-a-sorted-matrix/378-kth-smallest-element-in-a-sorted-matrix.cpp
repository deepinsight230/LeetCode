class Solution {
public:
    int helper(int mid, vector<vector<int>>& matrix, int n){
        int i=0, j=n-1;
        int ans=0;
        for(;i<n;i++){
            for(;j>=0;j--){
                if(matrix[i][j]<=mid){
                    ans+=j+1; break;
                }
            }
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0], high=matrix[n-1][n-1];
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            int idx=helper(mid, matrix, n);
            if(idx>=k) ans=mid, high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};