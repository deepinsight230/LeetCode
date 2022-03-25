class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long addn=goal-sum;
        long long ans=ceil(abs(addn)/(limit*1.0));
        return ans;
    }
};