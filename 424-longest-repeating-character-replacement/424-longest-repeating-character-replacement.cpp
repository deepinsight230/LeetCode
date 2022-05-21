class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int i=0, j=0, n=s.size(), ans=0;
        while(j<n){
            mp[s[j]]++;
            int winlen=j-i+1;
            int mfreq=0;
            for(auto m: mp){
                mfreq=max(mfreq, m.second);
            }
            int extras=winlen-mfreq;
            if(extras<=k){
                ans=max(ans, winlen);
                j++;
            }
            else{
                while(extras>k){
                    mp[s[i]]--;
                    i++;
                    winlen=j-i+1;
                    mfreq=0;
                    for(auto m: mp){
                        mfreq=max(mfreq, m.second);
                    }
                    extras=winlen-mfreq;
                }
                j++;
            }
        }
        return ans;
    }
};