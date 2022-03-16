class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int bsp=-prices[0], ssp=0;
        for(int i=1;i<prices.size();i++){
            bsp=max(bsp, ssp-prices[i]);
            ssp=max(ssp, bsp+prices[i]-fee);
        }
        return ssp;
    }
};