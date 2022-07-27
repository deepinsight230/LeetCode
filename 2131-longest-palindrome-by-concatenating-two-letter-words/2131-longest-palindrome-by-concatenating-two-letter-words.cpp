class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        int ans=0;
        bool flag=false;
        for(auto m: mp){
            string s=m.first;
            int freq=m.second;
            string rev=s;
            reverse(rev.begin(), rev.end());
            if(s==rev){
                if(freq%2==1 && !flag){
                    ans+=2*freq;
                    flag=true;
                }
                else if(freq%2==1 && flag){
                    ans+=2* (freq-1);
                }
                else ans+=2*freq;
            }
            else{
                if(mp.find(rev)==mp.end()) continue;
                ans+=2*min(mp[s], mp[rev]);
                // mp.erase(s);
            }
            // cout<<ans<<" "<<s<<endl;
        }
        return ans;
    }
};