// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        vector<vector<int>> move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = 0, pos = 0;
        
        while(x >= 0 && x < n && y >= 0 && y < m) {
            if(matrix[x][y] == 0) {
                x += move[pos][0];
                y += move[pos][1];
            } else {
                // update directions
                pos = (pos + 1) % 4;
                matrix[x][y] = 0;
            }
        }
        
        // revert the movement
        x -= move[pos][0];
        y -= move[pos][1];
        
        return {x, y};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends