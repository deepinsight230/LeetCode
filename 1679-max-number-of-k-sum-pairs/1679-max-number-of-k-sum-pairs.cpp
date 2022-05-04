class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(k-nums[i])!=mp.end()){
                mp[k-nums[i]]--;
                if(mp[k-nums[i]]==0) mp.erase(k-nums[i]);
                cnt++;
            }
            else mp[nums[i]]++;
        }
        return cnt;
    }
};