class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int origColor, int newColor, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || grid[i][j] != origColor) return;
        vis[i][j]=1;
        grid[i][j]=newColor;
        dfs(i+1, j, grid, vis, origColor, newColor, m, n);
        dfs(i, j+1, grid, vis, origColor, newColor, m, n);
        dfs(i-1, j, grid, vis, origColor, newColor, m, n);
        dfs(i, j-1, grid, vis, origColor, newColor, m, n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(), n=image[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        if(image[sr][sc] != newColor) dfs(sr, sc, image, vis, image[sr][sc], newColor, m, n);
        return image;
    }
};