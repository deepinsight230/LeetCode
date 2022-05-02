class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int s=0, itr=0;
        while(itr<nums.size()){
            if(nums[itr]%2==0){
                swap(nums[s], nums[itr]);
                s++;
            }
            itr++;
        }
        return nums;
    }
};