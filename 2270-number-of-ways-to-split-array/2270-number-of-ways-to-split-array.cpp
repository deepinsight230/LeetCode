class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n=nums.size(), sum=0, currsum=0, cnt=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        for(int i=0;i<n-1;i++){
            currsum+=nums[i];
            if(currsum>=(sum-currsum)) cnt++;
        }
        return cnt;
    }
};