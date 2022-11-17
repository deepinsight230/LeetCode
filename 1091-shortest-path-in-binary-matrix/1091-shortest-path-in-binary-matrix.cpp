class Solution {
public:
    vector<int> x_dir{-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> y_dir{-1, 0, 1, -1, 1, -1, 0, 1};
    bool isValid(int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    int bfs(vector<vector<int>>& grid, int m, int n, vector<vector<int>> &vis){
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0]=1;
        int cnt=0;
        bool flag=false;
        while(!q.empty() && !flag){
            int sz=q.size();
            cnt++;
            for(int i=0;i<sz && !flag;i++){
                int x=q.front().first;
                int y=q.front().second;
                if(x==m-1 && y==n-1) return cnt;
                q.pop();
                int new_x, new_y;
                for(int j=0;j<8;j++){
                    new_x=x+x_dir[j];
                    new_y=y+y_dir[j];
                    if(isValid(new_x, new_y, m, n) && vis[new_x][new_y]==0 && grid[new_x][new_y]==0) q.push({new_x, new_y}), vis[new_x][new_y]=1;
                }
            }
        }
        if(!flag) return -1;
        return cnt;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0] || grid[m-1][n-1]) return -1;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int ans=bfs(grid, m, n, vis);
        return (ans==0)?-1:ans;
    }
};