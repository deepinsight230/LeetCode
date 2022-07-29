class Solution {
public:
    void graphBuilder(vector<vector<int>>& stones, vector<int> adj[1001]){
        int n=stones.size();
        for(int i=0;i<n;i++){
            int x=stones[i][0], y=stones[i][1];
            for(int j=i+1;j<n;j++){
                int xx=stones[j][0], yy=stones[j][1];
                if(x==xx || y==yy){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto child: adj[node]){
            if(vis[child]==0) dfs(child, adj, vis);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int cnt=0, n=stones.size();
        vector<int> adj[n];
        graphBuilder(stones, adj);
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return n-cnt;
    }
};