class Solution {
public:
    string transform(string s){
        string ans="";
        int n=s.size();
        for(int i=0;i<n;){
            int j=i, cnt=0;
            while(j<n && s[j]==s[i]){
                cnt++;
                j++;
            }
            ans+='0'+cnt;
            ans+=s[i];
            i=j;
        }
        return ans;
    }
    string helper(int n){
        if(n==1) return "1";
        string temp=helper(n-1);
        return transform(temp);
    }
    string countAndSay(int n) {
        return helper(n);
    }
};