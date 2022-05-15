class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i: nums) sum+=i;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            if(currsum==(sum-currsum-nums[i])) return i;
            currsum+=nums[i];
        }
        return -1;
    }
};