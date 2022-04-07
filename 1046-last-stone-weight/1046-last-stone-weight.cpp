class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++) pq.push(stones[i]);
        while(pq.size()>1){
            int mx1=pq.top(); pq.pop();
            int mx2=pq.top(); pq.pop();
            pq.push(abs(mx1-mx2));
        }
        return pq.top();
    }
};