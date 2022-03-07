class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xxory=0;
        for(int i: nums) xxory^=i;
        int rsbm=xxory&(-xxory);
        int x=0, y=0;
        for(int i: nums){
            if(i&rsbm) x^=i;
            else y^=i;
        }
        return {x,y};
    }
};