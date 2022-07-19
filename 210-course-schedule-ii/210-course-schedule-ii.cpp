class Solution {
public:
    void kahn(queue<int> &q, vector<int> adj[], vector<int> &indeg, vector<int> &ans){
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto child: adj[node]){
                    indeg[child]--;
                    if(indeg[child]==0) q.push(child);
                }
            }
        }
    }
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int> adj[n], ans, indeg(n, 0);
        for(int i=0;i<arr.size();i++){
            int u=arr[i][0], v=arr[i][1];
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            for(auto child: adj[i]){
                indeg[child]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        kahn(q, adj, indeg, ans);
        if(ans.size()==n){
            return ans;
        }
        return {};
    }
};