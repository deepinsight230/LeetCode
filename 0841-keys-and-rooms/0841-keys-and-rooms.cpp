class Solution {
public:
    void graphBuilder(vector<int> adj[], vector<vector<int>> &rooms, int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
    }
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto child: adj[node]){
            if(!vis[child]) dfs(child, adj, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> adj[n];
        vector<int> vis(n, 0);
        graphBuilder(adj, rooms, n);
        dfs(0, adj, vis);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};