class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        string ans="";
        for(char ch: s) mp[ch]++;
        for(char ch: order){
            if(mp.find(ch)!=mp.end()){
                ans.append(mp[ch], ch);
                mp.erase(ch);
            }
        }
        for(auto m: mp){
            ans.append(m.second, m.first);
        }
        return ans;
    }
};