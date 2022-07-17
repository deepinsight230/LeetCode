class Solution {
public:
    bool isBi(int i, vector<int> &col, vector<vector<int>>& graph){
        if(col[i]==-1) col[i]=0;
        for(auto x: graph[i]){
            if(col[x]==-1){
                col[x]=1-col[i];
                bool res=isBi(x, col, graph);
                if(res==false) return false;
            }
            else{
                if(col[i]==col[x]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n, -1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                bool temp=isBi(i, col, graph);
                if(!temp) return false;
            }
        }
        return true;
    }
};