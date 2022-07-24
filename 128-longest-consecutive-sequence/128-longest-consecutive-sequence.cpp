class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n=nums.size(), ans=0;
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1)==s.end()){
                int cnt=0, x=nums[i];
                while(s.find(x)!=s.end()){
                    x++;
                    cnt++;
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};