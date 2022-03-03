class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt=0;
        for(int i=0;i<costs.size();i++){
            coins-=costs[i];
            if(coins>=0) cnt++;
            if(coins<0) break;
        }
        return cnt;
    }
};