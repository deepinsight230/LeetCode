#define mod 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<long long , long long> mp;
        int n=arr.size();
        for(int i=0;i<n;i++) mp[arr[i]]=1;
        for(int i=1;i<n;i++){
            long long count=0;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j] == 0){
                    if(mp.find(arr[i]/arr[j])!=mp.end()){
                        count+=mp[(arr[i]/arr[j])]*mp[arr[j]];
                    }
                }
            }
            mp[arr[i]]+=count;
        }
        int ans=0;
        for(auto m: mp){
            ans=(ans+(m.second%mod))%mod;
        }
        return ans;
    }
};