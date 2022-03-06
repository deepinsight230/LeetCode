class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size(), ans=0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int low=j+1, high=n-1, cnt=0, sum=nums[i]+nums[j];
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(nums[mid]<sum){
                        cnt=max(cnt, mid-j);
                        low=mid+1;
                    }
                    else high=mid-1;
                }
                ans+=cnt;
            }
        }
        return ans;
    }
};