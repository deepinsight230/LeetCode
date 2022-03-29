class Solution {
public:
    bool isValid(vector<int> &nums, int threshold, int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=(ceil(nums[i]/(mid*1.0)));
        }
        return (cnt<=threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=*max_element(nums.begin(), nums.end());
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(nums, threshold, mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};