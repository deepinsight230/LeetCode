class Solution {
public:
    string getSmallestString(int n, int k) {
        string str="";
        int i=26;
        while(n>1){
            while(double((k-i)/(n-1))<1) i--;
            str+=char(96+i);
            n--, k-=i;
        }
        str+=char(96+k);
        reverse(str.begin(), str.end());
        return str;
    }
};