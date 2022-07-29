class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char ch: t) mp[ch]++;
        int i=0, j=0, n=s.size(), m=t.size(), count=mp.size();
        int ans=INT_MAX;
        pair<int, int> pr;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }
            if(count>0) j++;
            else if(count==0){
                while(count==0){
                    if(ans> j-i+1){
                        ans=j-i+1;
                        pr={i, j};
                    }
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1) count++;
                    }
                    i++;
                }
                j++;
            }
        }
        return (ans==INT_MAX)?"":s.substr(pr.first, ans);
    }
};