class Solution {
public:
    vector<int> x_dir{0, 0, -1, 1};
    vector<int> y_dir{-1, 1, 0, 0};
    bool isValid(int i, int j, int m, int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n){
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) q.push({i, j}), vis[i][j]=1;
            }
        }
        int dis=-1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                int new_x, new_y;
                for(int j=0;j<4;j++){
                    new_x=x+x_dir[j];
                    new_y=y+y_dir[j];
                    if(isValid(new_x, new_y, m, n) && !vis[new_x][new_y] && grid[new_x][new_y] == 0){
                        q.push({new_x, new_y});
                        vis[new_x][new_y]=1;
                    }
                }
            }
            dis++;
        }
        return dis;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int ans=bfs(grid, vis, m, n);
        return (ans == 0)?-1:ans;
    }
};