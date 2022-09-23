class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int l=0, r=n-1;
        while(l <= r){
            int mid=l+(r-l)/2;
            bool f1=false, f2=false;
            if((mid-1)>=0){
                if(arr[mid] > arr[mid-1]) f1=true;
            }
            else f1=true;
            if((mid+1)<n){
                if(arr[mid] > arr[mid+1]) f2=true;
            }
            else f2=true;
            if(f1 && f2) return mid;
            if(!f1) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};