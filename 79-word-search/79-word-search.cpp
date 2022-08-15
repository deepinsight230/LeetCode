class Solution {
public:
    bool helper(int i, int j, vector<vector<char>>& board, int k, string &word, vector<vector<int>> &vis, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[k]) return false;
        if(vis[i][j]) return false;
        if(k==word.size()-1) return true;
        vis[i][j]=1;
        bool temp1=helper(i+1, j, board, k+1, word, vis, m, n);
        bool temp2=helper(i-1, j, board, k+1, word, vis, m, n);
        bool temp3=helper(i, j+1, board, k+1, word, vis, m, n);
        bool temp4=helper(i, j-1, board, k+1, word, vis, m, n);
        vis[i][j]=0;
        return (temp1||temp2||temp3||temp4);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>> vis(m, vector<int> (n, 0));
                bool temp=helper(i, j, board, 0, word, vis, m, n);
                if(temp) return true;
            }
        }
        return false;
    }
};