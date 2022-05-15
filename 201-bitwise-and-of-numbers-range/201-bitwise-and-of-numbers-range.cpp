class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0||right==0) return 0;
        int d1=log2(right);
        int d2=log2(left);
        if(d1!=d2) return 0;
        int x=left;
        for(long long i=left;i<=right;i++){
            x&=i;
        }
        return x;
    }
};