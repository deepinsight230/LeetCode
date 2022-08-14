class Solution {
public:
    bool isCycle(int node, int par, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto child: adj[node]){
            if(vis[child]==0){
                bool temp=isCycle(child, node, adj, vis);
                if(temp==true) return true;
            }
            else{
                if(child!=par) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> adj[n+1];
        for(int i=0;i<n;i++){
            int u=edges[i][0], v=edges[i][1];
            adj[u].push_back(v), adj[v].push_back(u);
            vector<int> vis(n+1, 0);
            if(isCycle(u, -1, adj, vis)) return {u, v};
        }
        return {};
    }
};