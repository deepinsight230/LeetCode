class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n=points.size();
        int currend=points[0][1], arrows=1;
        for(int i=0;i<n-1;i++){
            int nextstart=points[i+1][0];
            if(nextstart<=currend){ //overlaps
                currend=min(currend, points[i+1][1]);
            }
            else{ //non-overlapping
                arrows++;
                currend=points[i+1][1];
            }
        }
        return arrows;
    }
};