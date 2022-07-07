class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int i=startPos[0], j=startPos[1], ie=homePos[0], je=homePos[1], ans=0;
        while(i<ie){
            ans+=rowCosts[i+1];
            i++;
        }
        while(i>ie){
            ans+=rowCosts[i-1];
            i--;
        }
        while(j<je){
            ans+=colCosts[j+1];
            j++;
        }
        while(j>je){
            ans+=colCosts[j-1];
            j--;
        }
        return ans;
    }
};