class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if(time.size()==1) return 0;
        unordered_map<int, int> mp;
        int ans=0;
        for(int i=0;i<time.size();i++){
            int req=((time[i]%60)==0)?0:60-(time[i]%60);
            if(mp.find(req)!=mp.end()){
                ans+=mp[req];
            }
            mp[time[i]%60]++;
        }
        return ans;
    }
};