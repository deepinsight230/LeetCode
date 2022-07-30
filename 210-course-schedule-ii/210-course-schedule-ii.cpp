class Solution {
public:
    void builder(vector<int> adj[], vector<int> &indeg, int n, vector<vector<int>>& pre){
        for(int i=0;i<pre.size();i++){
            indeg[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
        }
    }
    void bfs(vector<int> &indeg, int n, vector<int> adj[], vector<int> &ans){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int node=q.front();
                ans.push_back(node);
                q.pop();
                for(auto child: adj[node]){
                    indeg[child]--;
                    if(indeg[child]==0){
                        q.push(child);
                    }
                }
            }
        }
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indeg(n, 0), adj[n];
        vector<int> ans;
        builder(adj, indeg, n, pre);
        bfs(indeg, n, adj, ans);
        if(ans.size()==n) return ans;
        else return {};
    }
};