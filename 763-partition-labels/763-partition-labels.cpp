class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        vector<int> ans;
        for(char ch: s){
            mp[ch]++;
        }
        string discovered="";
        int cnt=0;
        bool flag;
        for(int i=0;i<s.size();i++){
            cnt++;
            if(discovered.find(s[i])==string::npos) discovered+=s[i];
            mp[s[i]]--;
            flag=true;
            for(char ch: discovered){
                if(mp[ch]!=0){
                    flag=false;
                    break;
                }
            }
            if(flag==true) ans.push_back(cnt), discovered="", cnt=0;
        }
        return ans;
    }
};