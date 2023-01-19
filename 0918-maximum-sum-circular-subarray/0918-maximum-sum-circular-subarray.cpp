class Solution {
public:
    int kadane(vector<int> &nums, int n){
        int curr_sum=0, max_sum=nums[0];
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            max_sum=max(max_sum, curr_sum);
            if(curr_sum<0) curr_sum=0;
        }
        return max_sum;
    }
    int kadane2(vector<int> &nums, int n){
        int curr_sum=0, min_sum=nums[0];
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            min_sum=min(curr_sum, min_sum);
            if(curr_sum>0) curr_sum=0;
        }
        return min_sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans1=kadane(nums, n);
        int t_sum=accumulate(nums.begin(), nums.end(), 0);
        int ans2=kadane2(nums, n);
        return ((t_sum-ans2) == 0)?ans1:max(ans1, (t_sum-ans2));
    }
};