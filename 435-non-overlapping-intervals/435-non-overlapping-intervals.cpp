class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size(), cnt=0;
        sort(intervals.begin(), intervals.end());
        int currend, nextstart;
        currend=intervals[0][1];
        for(int i=0;i<n-1;i++){
            nextstart=intervals[i+1][0];
            if(currend<=nextstart){ //non-overlapping
                currend=intervals[i+1][1];
            }
            else{ //overlapping
                cnt++;
                currend=min(currend, intervals[i+1][1]);
            }
        }
        return cnt;
    }
};