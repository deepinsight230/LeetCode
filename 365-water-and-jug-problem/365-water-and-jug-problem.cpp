class Solution {
public:
    bool canMeasureWater(int c1, int c2, int target) {
        if(target> c1+c2) return false;
        int g=__gcd(c1, c2);
        if(target%g!=0) return false;
        return true;
    }
};