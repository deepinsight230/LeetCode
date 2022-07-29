class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            unordered_map<char, char> mp, mp1;
            bool flag=true;
            for(int j=0;j<pattern.size();j++){
                mp1[word[j]]++;
                char ch=pattern[j];
                if(mp.find(ch)==mp.end()) mp[ch]=word[j];
                else{
                    char mapping=mp[ch];
                    if(mapping!=word[j]){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag && mp.size()==mp1.size()) ans.push_back(word);
        }
        return ans;
    }
};