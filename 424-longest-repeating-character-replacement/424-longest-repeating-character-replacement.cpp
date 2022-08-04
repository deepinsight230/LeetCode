class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int i=0, j=0, n=s.size();
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            int maxfreq=0;
            for(auto m: mp) maxfreq=max(maxfreq, m.second);
            int winLen=j-i+1;
            if(winLen-maxfreq <=k){
                ans=max(ans, winLen);
                j++;
            }
            else{
                while(winLen-maxfreq>k){
                    mp[s[i]]--;
                    i++;
                    for(auto m: mp) maxfreq=max(maxfreq, m.second);
                    winLen=j-i+1;
                }
                j++;
            }
        }
        return ans;
    }
};