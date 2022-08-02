class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), revdistort=-1, nextgrt=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){ revdistort=i; break;}
        }
        if(revdistort==-1) goto here;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[revdistort]){
                nextgrt=i;
                break;
            }
        }
        swap(nums[revdistort], nums[nextgrt]);
        here:
        sort(nums.begin()+revdistort+1, nums.end());
    }
};