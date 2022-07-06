class Solution {
public:
    int fib(int n) {
        int i=0, a=-1, b=1, c=0;
        while(i<=n){
            c=a+b;
            a=b;
            b=c;
            i++;
        }
        return c;
    }
};