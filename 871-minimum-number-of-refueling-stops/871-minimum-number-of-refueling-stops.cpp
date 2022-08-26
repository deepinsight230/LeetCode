class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int fuel=startFuel, cnt=0, i=0, n=stations.size();
        // if(n==0) return (fuel>=target)?0:-1;
        while(i<n){
            if(target<=fuel) return cnt;
            while(i<n && stations[i][0]<=fuel){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            fuel+=pq.top();
            pq.pop();
            cnt++;
        }
        while(!pq.empty() && fuel<target){
            fuel+=pq.top();
            pq.pop();
            cnt++;
        }
        // cout<<i<<" "<<fuel<<endl;
        return (fuel>=target)?cnt:-1;
    }
};