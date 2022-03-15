class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt=0;
        string str="", ans="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(') cnt++;
            else if(ch==')') cnt--;
            if(cnt>=0) str+=ch;
            if(cnt<0) cnt=0;
        }
        cnt=0;
        for(int i=str.size()-1;i>=0;i--){
            char ch=str[i];
            if(ch=='(') cnt--;
            else if(ch==')') cnt++;
            if(cnt>=0) ans+=ch; 
            if(cnt<0) cnt=0;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};