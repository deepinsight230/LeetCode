#define pii pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i: nums) mp[i]++;
        for(auto m: mp){
            pq.push({m.second, m.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};