class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, ans=0;
        unordered_map<char, int> mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp[s[j]]==1) j++;
            else{
                while(mp[s[j]]>1){
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
            ans=max(ans, j-i);
        }
        return ans;
    }
};