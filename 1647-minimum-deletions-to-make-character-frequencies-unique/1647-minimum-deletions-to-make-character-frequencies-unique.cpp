class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp1;
        int mx=0;
        for(char ch: s){
            mp1[ch]++;
            mx=max(mx, mp1[ch]);
        }
        vector<int> mp2(mx+1, 0);
        for(auto m: mp1){
            mp2[m.second]++;
        }
        int ans=0;
        for(int i=mx;i>0;i--){
            int diff=mp2[i]-1;
            if(diff>0){
                ans+=diff;
                if(i-1>0) mp2[i-1]+=diff;
            }
        }
        return ans;
    }
};