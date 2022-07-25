class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto f=lower_bound(nums.begin(), nums.end(), target);
        auto l=upper_bound(nums.begin(), nums.end(), target);
        if(f==nums.end() || *f != target) return {-1, -1};
        int ff=f-nums.begin();
        int ll=l-nums.begin();
        return {ff, ll-1};
    }
};