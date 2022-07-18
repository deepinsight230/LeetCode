class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto child: adj[node]){
            if(vis[child]==0){
                bool temp=dfs(child, adj, vis);
                if(temp) return true;
            }
            else return true;
        }
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> adj[n];
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1) adj[i].push_back(leftChild[i]);
            if(rightChild[i]!=-1) adj[i].push_back(rightChild[i]);
        }
        int node;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1) s.insert(leftChild[i]);
            if(rightChild[i]!=-1) s.insert(rightChild[i]);
        }
        for(int i=0;i<n;i++){
            if(s.find(i)==s.end()){
                node=i;
                break;
            }
        }
        bool res=dfs(node, adj, vis);
        if(res==true) return false;
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};