class Solution
{
    public:
    void kahn(queue<int> &q, vector<int> adj[], vector<int> &indeg, int &ans)
    {
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int node=q.front();
                q.pop();
                ans++;
                for(auto child: adj[node]){
                    indeg[child]--;
                    if(indeg[child]==0) q.push(child);
                }
            }
        }
    }
    bool canFinish(int n, vector<vector<int>> &arr)
    {
        vector<int> adj[n];
        vector<int> indeg(n, 0);
        for(int i=0; i<arr.size();i++){
            int u=arr[i][0], v=arr[i][1];
            adj[u].push_back(v);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(auto child: adj[i]){
                indeg[child]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        kahn(q, adj, indeg, ans);
        if(ans ==n) return true;
        return false;
    }
};