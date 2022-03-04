class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0;
        int sum=0, ans=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum<target) j++;
            else if(sum==target){
                ans=min(ans, j-i+1);
                sum-=nums[i];
                i++, j++;
            }
            else{
                while(sum>=target){
                    ans=min(ans, j-i+1);
                    sum-=nums[i];
                    i++;
                }
                j++;
            }
        }
        return (ans==INT_MAX)?0:ans;
    }
};