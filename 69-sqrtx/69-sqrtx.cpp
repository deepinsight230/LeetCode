class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return x;
        int low=0,high=x;
        int res=0;
        while(low<high){
            int mid=(low+high)/2;
            if(mid>x/mid) high=mid;
            else{
                res=mid;
                low=mid+1;
            }
        }
        return res;
    }
};