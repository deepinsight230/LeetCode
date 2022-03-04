class Solution {
public:
    string reverseWords(string s) {
        s+=' ';
        string ans="";
        int i=0, j=0;
        while(j<s.size()){
            if(s[j]!=' ') j++;
            else if(s[j]==' '&&i==j) i++, j++;
            else if(s[j]==' '){
                string temp=s.substr(i, j-i+1);
                ans=temp+ans;
                i=j;
            }
        }
        ans.pop_back();
        return ans;
    }
};