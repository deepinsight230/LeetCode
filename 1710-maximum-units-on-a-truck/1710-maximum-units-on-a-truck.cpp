class Solution {
public:
    static bool myCmp(vector<int> a, vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        sort(boxes.begin(), boxes.end(), myCmp);
        int ans=0, i=0;
        while(i<boxes.size()&&boxes[i][0]<=truckSize){
            ans+=(boxes[i][0]*boxes[i][1]);
            truckSize-=boxes[i][0];
            i++;
        }
        if(i<boxes.size()) ans+=truckSize*boxes[i][1];
        return ans;
    }
};