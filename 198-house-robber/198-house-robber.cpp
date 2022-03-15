class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int pinc=0, pexc=0;
        for(int i=0;i<n;i++){
            int temp=max(pinc, pexc+nums[i]);
            pexc=pinc;
            pinc=temp;
        }
        return pinc;
    }
};