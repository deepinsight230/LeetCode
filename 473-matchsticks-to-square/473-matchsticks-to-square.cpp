class Solution {
public:
    bool helper(int i, int s1, int s2, int s3, int s4, int side, vector<int> &arr, int n){
        // if(i==n) return false;
        if(s1==side && s2==side && s3==side && s4==side) return true;
        if(s1+arr[i]<=side) if(helper(i+1, s1+arr[i], s2, s3, s4, side, arr, n)) return true;
        if(s2+arr[i]<=side) if(helper(i+1, s1, s2+arr[i], s3, s4, side, arr, n)) return true;
        if(s3+arr[i]<=side) if(helper(i+1, s1, s2, s3+arr[i], s4, side, arr, n)) return true;
        if(s4+arr[i]<=side) if(helper(i+1, s1, s2, s3, s4+arr[i], side, arr, n)) return true;
        return false;
    }
    bool makesquare(vector<int>& arr) {
        int n=arr.size();
        if(n<4) return false;
        int sum=accumulate(arr.begin(), arr.end(), 0);
        if(sum%4 != 0) return false;
        int side=sum/4;
        sort(arr.begin(), arr.end(), greater<int> ());
        return helper(0, 0, 0, 0, 0, side, arr, n);
    }
};