class Solution {
public:
    int ans=0;
    void subsets(int idx, vector<int> &ds, vector<int> &nums, int n){
        if(idx == n){
            int xr=0;
            for(int i=0;i<ds.size();i++){
                xr^=ds[i];
            }
            ans+=xr;
            return;
        }
        ds.push_back(nums[idx]);
        subsets(idx+1, ds, nums, n);
        ds.pop_back();
        subsets(idx+1, ds, nums, n);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ds;
        subsets(0, ds, nums, n);
        return ans;
    }
};