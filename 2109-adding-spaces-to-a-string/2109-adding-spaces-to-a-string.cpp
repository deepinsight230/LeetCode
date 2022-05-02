class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int j=0;
        if(spaces[0]==0) j++, ans+=' ';
        for(int i=0;i<s.size();i++){
            ans+=s[i];
            if(j<spaces.size()&&i+1==spaces[j]){
                ans+=' ';
                j++;
            }
        }
        return ans;
    }
};