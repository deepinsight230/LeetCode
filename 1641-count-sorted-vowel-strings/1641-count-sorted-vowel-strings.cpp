class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> arr(n, vector<int> (5, 1));
        for(int i=1;i<n;i++){
            for(int j=3;j>=0;j--){
                arr[i][j]=arr[i-1][j]+arr[i][j+1];
            }
        }
        int ans=0;
        for(int i=0;i<5;i++)
            ans+=arr[n-1][i];
        return ans;
    }
};