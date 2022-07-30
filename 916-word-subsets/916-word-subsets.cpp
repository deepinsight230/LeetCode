class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int m=words1.size(), n=words2.size();
        unordered_map<char, int> mp;
        for(int i=0;i<n;i++){
            string str=words2[i];
            unordered_map<char, int> mp1;
            for(char ch: str){
                mp1[ch]++;
            }
            for(auto m: mp1){
                char ch=m.first;
                mp[ch]=max(mp[ch], mp1[ch]);
            }
        }
        for(int i=0;i<m;i++){
            string str=words1[i];
            unordered_map<char, int> mp2;
            for(char ch: str) mp2[ch]++;
            bool flag=true;
            for(auto m: mp){
                char ch=m.first;
                if(mp2.find(ch)==mp2.end() || mp2[ch]<mp[ch]){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(str);
        }
        return ans;
    }
};