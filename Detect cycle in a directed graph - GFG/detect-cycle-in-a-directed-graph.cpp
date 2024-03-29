//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto child: adj[node]){
            if(dfsvis[child]) return true;
            if(vis[child]) continue;
            else if(helper(child, adj, vis, dfsvis)) return true;
        }
        dfsvis[node]=0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n, 0);
        vector<int> dfsvis(n, 0);
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                if(helper(i, adj, vis, dfsvis)){
                    // cout<<i<<endl;
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends