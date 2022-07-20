class Solution {
public:
    void dfs(int node, int &cnt, vector<int> adj[], vector<int> &vis, vector<int> &cc){
        vis[node]=1;
        cnt++;
        for(auto child: adj[node]){
            if(vis[child]==0){
                dfs(child, cnt, adj, vis, cc);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> cc;
        vector<int> adj[n], vis(n, 0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int cnt=0;
                dfs(i, cnt, adj, vis, cc);
                cc.push_back(cnt);
            }
        }
        long long ans=0;
        for(int i=0;i<cc.size();i++){
            long long rem=n-cc[i];
            ans+=(rem*cc[i]);
            n-=cc[i];
        }
        return ans;
    }
};