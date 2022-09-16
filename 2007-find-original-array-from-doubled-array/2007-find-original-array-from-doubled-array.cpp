class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2 == 1) return {};
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[changed[i]]++;
        }
        vector<int> ans;
        for(auto x: mp){
            int num=x.first;
            int freq=x.second;
            int doub=num*2;
            if(mp.find(doub) == mp.end()) return {};
            else{
                if(num == 0){
                    for(int i=0;i<freq/2;i++) ans.push_back(num);
                    mp.erase(num);
                }
                else{
                    for(int i=0;i<freq;i++) ans.push_back(num);
                    mp[doub]-=freq;
                    if(mp[doub] < 0) return {};
                    else if(mp[doub] == 0) mp.erase(doub);
                }
            }
        }
        return ans;
    }
};