class Solution {
public:
    bool isValid(vector<int> &nums, int m, int mid){
        int sum=0, cnt=1;
        for(int i=0;i<nums.size();i++){
            if((sum+nums[i])<=mid) sum+=nums[i];
            else{
                sum=nums[i];
                cnt++;
            }
        }
        return (cnt<=m);
    }
    int splitArray(vector<int>& nums, int m) {
        int low=INT_MIN, high=0, n=nums.size(), ans;
        for(int i=0;i<n;i++){
            low=max(low, nums[i]);
            high+=nums[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(nums, m, mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};