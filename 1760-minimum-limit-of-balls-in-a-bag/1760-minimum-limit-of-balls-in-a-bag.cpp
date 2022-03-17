class Solution {
public:
    bool isValid(vector<int> &nums, int k, int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=(nums[i]-1)/mid;
        }
        return (cnt<=k);
    }
    int minimumSize(vector<int>& nums, int k) {
        int low=1, high=*max_element(nums.begin(), nums.end());
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(nums, k, mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};