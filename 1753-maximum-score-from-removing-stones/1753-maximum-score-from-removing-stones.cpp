class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int cnt=0;
        while(pq.size()>1){
            cnt++;
            int u=pq.top(); pq.pop();
            int v=pq.top(); pq.pop();
            if(--u>0) pq.push(u);
            if(--v>0) pq.push(v);
        }
        return cnt;
    }
};