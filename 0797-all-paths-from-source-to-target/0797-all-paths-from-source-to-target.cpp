class Solution {
public:
    void graphBuilder(vector<int> adj[], vector<vector<int>> &graph, int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
    }
    void dfs(int node, int n, vector<int> &ds, vector<vector<int>> &ans, vector<int> adj[]){
        ds.push_back(node);
        if(node == (n-1)){
            ans.push_back(ds);
            return;
        }
        for(auto child: adj[node]){
            dfs(child, n, ds, ans, adj);
            ds.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=graph.size();
        vector<int> adj[n];
        graphBuilder(adj, graph, n);
        dfs(0, n, ds, ans, adj);
        return ans;
    }
};