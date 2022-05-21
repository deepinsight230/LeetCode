class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0, n=nums.size();
        int zeroes=0, ones=0, ans=0;
        while(j<n){
            if(nums[j]==0) zeroes++;
            else ones++;
            if(zeroes<=k){
                
                j++;
            }
            else{
                while(zeroes>k){
                    if(nums[i]==0) zeroes--;
                    else ones--;
                    i++;
                }
                j++;
            }
            ans=max(ans, j-i);
        }
        return ans;
    }
};