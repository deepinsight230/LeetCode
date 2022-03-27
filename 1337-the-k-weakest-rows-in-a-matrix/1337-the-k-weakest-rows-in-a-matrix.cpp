#define pii pair<int, int>
class Solution {
public:
    // static comp(pair<int, int> p1, pair<int, int> p2){
    //     if(p1.first!=p2.first) return p1.first>p2.first;
    //     else p1.second<p2.second;
    // }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pii> pq;
        int m=mat.size(), n=mat[0].size();
        vector<int> ones(m);
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) cnt++;
            }
            ones[i]=cnt;
        }
        for(int i=0;i<m;i++){
            pq.push({ones[i], i});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};