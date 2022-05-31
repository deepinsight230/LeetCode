class Solution {
public:
    string lcs(string s1, string s2){
        int m=s1.size(), n=s2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string str="";
        int i=m, j=n;
        while(i>0&&j>0){
            if(s1[i-1]==s2[j-1]){
                str+=s1[i-1];
                i--, j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        string lc=lcs(s1, s2);
        int i=0, j=0, k=0;
        int m=s1.size(), n=s2.size();
        string ans="";
        while(i<m&&j<n&&k<lc.size()){
            if((s1[i]!=s2[j])&&(s1[i]!=lc[k]&&s2[j]!=lc[k])){
                ans+=s1[i];
                ans+=s2[j];
                i++, j++;
                // cout<<"1";
            }
            else if(s1[i]==s2[j]&&(s1[i]==lc[k])){
                ans+=s1[i];
                i++, j++, k++;
                // cout<<"2";
            }
            else if(s1[i]!=s2[j]&&(s1[i]==lc[k]||s2[j]==lc[k])){
                if(s1[i]!=lc[k]){
                    ans+=s1[i];
                    i++;
                    // cout<<"3";
                }
                else if(s2[j]!=lc[k]){
                    ans+=s2[j];
                    j++;
                    // cout<<"4";
                }
            }
        }
        while(i<m) {ans+=s1[i], i++;}
        while(j<n) {ans+=s2[j], j++;}
        return ans;
    }
};