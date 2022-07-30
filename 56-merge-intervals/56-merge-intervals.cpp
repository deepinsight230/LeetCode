class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> interval(2);
        interval[0]=intervals[0][0], interval[1]=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=interval[1]){
                interval[0]=min(interval[0], intervals[i][0]);
                interval[1]=max(interval[1], intervals[i][1]);
            }
            else{
                ans.push_back(interval);
                interval=intervals[i];
            }
        }
        ans.push_back(interval);
        return ans;
    }
};