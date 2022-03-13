class Solution {
public:
    int kadane(vector<int> &nums){
        int sum=0, ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans, sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int max1=kadane(nums);
        if(max1<0) return max1;
        int tsum=0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
            nums[i]=-nums[i];
        }
        int max2=tsum+kadane(nums);
        // cout<<max1<<" "<<max2;
        return max(max1, max2);
    }
};