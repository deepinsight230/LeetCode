class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }
        for(auto m: mp){
            if(m.second==1) return m.first;
        }
        return 0;
    }
};