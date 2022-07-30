class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto child: adj[node]){
            if(vis[child]==0) dfs(child, adj, vis);
        }
    }
    void graphBuilder(vector<vector<int>>& grid, vector<int> adj[], int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && grid[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> adj[n];
        vector<int> vis(n, 0);
        graphBuilder(grid, adj, n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};