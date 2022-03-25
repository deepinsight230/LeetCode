class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i=0;i<costs.size();i++){
            int diff=abs(costs[i][0]-costs[i][1]);
            pq.push({diff, {costs[i][0], costs[i][1]}});
        }
        int ans=0, cnt1=0, cnt2=0, n=costs.size();
        while(!pq.empty()){
            pair<int, int> csts=pq.top().second;
            pq.pop();
            if((csts.first<=csts.second&&cnt1<n/2)||(cnt2>=n/2)){
                ans+=csts.first;
                cnt1++;
            }
            else if((csts.second<csts.first&&cnt2<n/2)||(cnt1>=n/2)){
                ans+=csts.second;
                cnt2++;
            }
        }
        return ans;
    }
};