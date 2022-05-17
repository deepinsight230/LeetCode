class Solution {
public:
    void helper(int idx, int &ans, int n, vector<int> &nums){
        if(idx==n){
            ans++;
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[idx], nums[i]);
            if((nums[idx]%(idx+1)==0)||((idx+1)%nums[idx]==0)) helper(idx+1, ans, n, nums);
            swap(nums[idx], nums[i]);
        }
    }
    int countArrangement(int n) {
        int ans=0;
        vector<int> nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        helper(0, ans, n, nums);
        return ans;
    }
};