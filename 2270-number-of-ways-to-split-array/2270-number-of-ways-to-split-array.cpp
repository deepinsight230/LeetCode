class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> psum(n), ssum(n);
        psum[0]=nums[0], ssum[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            psum[i]=psum[i-1]+nums[i];
        for(int i=n-2;i>=0;i--)
            ssum[i]=ssum[i+1]+nums[i];
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(psum[i]>=ssum[i+1]) cnt++;
        }
        return cnt;
    }
};