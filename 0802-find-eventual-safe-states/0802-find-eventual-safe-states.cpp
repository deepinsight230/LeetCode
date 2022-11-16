class Solution {
public:
    void graphBuilder(vector<int> adj[], vector<vector<int>> &graph){
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
    }
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis, vector<int> &ans){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto child: adj[node]){
            // cout<<node<<" "<<child<<endl;
            if(!vis[child]){
                if(dfs(child, adj, vis, dfsvis, ans)) return true;
            }
            else if(dfsvis[child]) return true;
        }
        dfsvis[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        graphBuilder(adj, graph);
        vector<int> vis(n, 0);
        vector<int> dfsvis(n, 0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i, adj, vis, dfsvis, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};