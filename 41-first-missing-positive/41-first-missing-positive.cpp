class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <= 0) nums[i]=10000000;
        }
        for(int i=0;i<n;i++){
            int idx=abs(nums[i])-1;
            if(idx>=0 && idx<n){
                nums[abs(idx)]=-abs(nums[abs(idx)]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};