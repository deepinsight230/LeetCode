class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans, mn=INT_MAX;
        for(int i=0;i<n;i++){
            int l=i+1, r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                int diff=abs(target-sum);
                if(diff<mn){
                    mn=diff;
                    ans=sum;
                }
                if(sum<target) l++;
                else if(sum>target) r--;
                else return target;
            }
        }
        return ans;
    }
};