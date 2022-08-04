class Solution {
public:
    string helper(int &i, string s){
        int num=0;
        string ans="";
        for(;i<s.size();i++){
            if(s[i]=='['){
                string temp=helper(++i, s);
                while(num--) ans+=temp;
                num=0;
            }
            else if(isalpha(s[i])) ans+=s[i];
            else if(isdigit(s[i])){
                num=num*10 + s[i]-'0';
            }
            else{
                return ans;
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int i=0;
        return helper(i, s);
    }
};