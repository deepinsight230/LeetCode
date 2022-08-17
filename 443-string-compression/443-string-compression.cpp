class Solution {
public:
    int compress(vector<char>& chars) {
        string ans="";
        int n=chars.size();
        for(int i=0;i<n;i++){
            int cnt=0, j=i;
            while(j < n && chars[j]==chars[i]){
                cnt++, j++;
            }
            ans+=chars[i];
            if(cnt>1){
                string temp=to_string(cnt);
                for(char ch: temp) ans+=ch;
            }
            i=j-1;
        }
        for(int i=0;i<ans.size();i++) chars[i]=ans[i];
        return ans.size();
    }
};