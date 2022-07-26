class Solution {
public:
    double champagneTower(int poured, int row, int glass) {
        int rows=row+1, cols=(2*rows)-1;
        vector<vector<double>> dp(rows, vector<double> (cols, 0.0));
        
        for(int i=0;i<rows; i++){
            int startCol=(cols/2)-i;
            for(int j=0;j<=i;j++){
                int col=startCol+(2*j);
                if(i==0 && i != rows-1){
                    double rem;
                    if(poured>1.0) rem=(double)poured-1;
                    else rem=0.0;
                    dp[i][col]=rem;
                }
                else if(i==0 && i== rows-1){
                    double rem;
                    if(poured==0) rem=0;
                    else rem=1;
                    dp[i][col]=rem;
                }
                else{
                    double rem, excess1=0.0, excess2=0.0;
                    if(col-1 >= 0) excess1=dp[i-1][col-1];
                    if(col+1 < cols) excess2=dp[i-1][col+1];
                    rem=excess1/2.0 + excess2/2.0;
                    if(i!= rows-1) dp[i][col]=max(0.0, rem-1.0);
                    else dp[i][col]=rem;
                }
            }
        }
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        int col=((cols/2)-row)+2*glass;
        double ans=dp[row][col];
        if(ans>1.0) ans=1.0;
        
        return ans;
    }
};