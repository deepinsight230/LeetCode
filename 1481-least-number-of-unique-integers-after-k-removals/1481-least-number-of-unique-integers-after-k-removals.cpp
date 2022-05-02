class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i: nums) mp[i]++;
        vector<vector<int>> arr;
        for(auto m: mp){
            arr.push_back({m.second, m.first});
        }
        sort(arr.begin(), arr.end());
        int i=0, n=arr.size();
        while(k>0&&i<arr.size()){
            if(arr[i][0]<=k) k-=arr[i][0], n--;
            else break;
            i++;
        }
        return n;
    }
};