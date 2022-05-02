class Solution {
public:
    void helper(vector<vector<char>>& board, int i, int j, int m, int n){
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='X'||board[i][j]=='Y') return;
        board[i][j]='Y';
        helper(board, i+1, j, m, n);
        helper(board, i-1, j, m, n);
        helper(board, i, j+1, m, n);
        helper(board, i, j-1, m, n);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') helper(board, i, 0, m, n);
            if(board[i][n-1]=='O') helper(board, i, n-1, m, n);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') helper(board, 0, j, m, n);
            if(board[m-1][j]=='O') helper(board, m-1, j, m, n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Y') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};