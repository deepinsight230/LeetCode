class Solution {
public:
    int counter(vector<vector<int>>& matrix, int mid, int n){
        int i=0, j=n-1;
        int c=0;
        for(;i<n;i++){
            for(;j>=0;j--){
                if(matrix[i][j]<=mid){c+=j+1; break;}
            }
        }
        return c;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        
        while(low<high){
            int mid=low+(high-low)/2;
            int count=counter(matrix, mid, n);
            if(count>=k) high=mid;
            else low=mid+1;
        }
        return low;
    }
};