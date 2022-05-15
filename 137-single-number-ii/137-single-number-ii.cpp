class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if((abs(nums[j])&(1<<i))!=0) cnt++;
            }
            if(cnt%3!=0) ans=ans+(pow(2, i));
        }
        int negans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==-ans) negans++;
        }
        return (negans==1)?-ans:ans;
    }
};