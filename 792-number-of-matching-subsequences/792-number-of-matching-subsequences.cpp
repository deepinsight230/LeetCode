class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, set<int>> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].insert(i);
        }
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string str=words[i];
            int prev=-1;
            bool flag=true;
            for(int j=0;j<str.size();j++){
                char ch=str[j];
                auto it=mp[ch].upper_bound(prev);
                if(it==mp[ch].end()){
                    flag=false;
                    break;
                }
                else prev=*it;
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};