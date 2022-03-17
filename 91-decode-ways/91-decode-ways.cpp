class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n, 0);
        if(s[0]!='0') dp[0]=1;
        if(n>1){
            if(s[0]=='0') dp[1]=0;
            else{
                if(s[1]=='0'&&(s[0]=='1'||s[0]=='2')) dp[1]=1;
                else if((s[0]=='1'&&s[1]!='0')||(s[0]=='2'&&s[1]<='6')) dp[1]=2;
                else if(s[1]!='0') dp[1]=1;
            }
        }
        for(int i=2;i<n;i++){
            if(s[i]=='0'&&s[i-1]=='0') //00
                dp[i]=0, cout<<i<<"00"<<endl;
            else if(s[i]=='0'&&(s[i-1]=='1'||s[i-1]=='2')) //10
                dp[i]=dp[i-2], cout<<i<<"10"<<endl;
            else if(s[i]!='0'&&s[i-1]=='0') //01
                dp[i]=dp[i-1], cout<<i<<"01"<<endl;
            else if((s[i-1]=='1'&&s[i]!='0')||(s[i-1]=='2'&&s[i]<='6')) //11
                dp[i]=dp[i-1]+dp[i-2], cout<<i<<"11"<<endl;
            else if(s[i]!='0')
                dp[i]=dp[i-1], cout<<i<<"33"<<endl;
        }
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        return dp[n-1];
    }
};