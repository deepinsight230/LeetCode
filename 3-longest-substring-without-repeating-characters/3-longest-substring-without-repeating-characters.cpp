class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n=s.size();
        int i=0, j=0, ans=0;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]==1) ans=max(ans, j-i+1), j++;
            else{
                while(mp[s[j]]==2){
                    mp[s[i]]--;
                    i++;
                }
                ans=max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
};