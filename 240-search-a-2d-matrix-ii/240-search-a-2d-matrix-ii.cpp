class Solution {
public:
    bool search(vector<int> &row, int target){
        int low=0, high=row.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(row[mid]==target) return true;
            if(row[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(search(matrix[i], target)) return true;
        }
        return false;
    }
};