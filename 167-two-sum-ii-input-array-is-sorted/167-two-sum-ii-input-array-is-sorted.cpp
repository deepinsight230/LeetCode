class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        int n=nums.size();
        int low=0, high=n-1;
        while(low<high){
            int sum=nums[low]+nums[high];
            if(sum==target) return {low+1, high+1};
            else if(sum<target) low++;
            else high--;
        }
        return {};
    }
};