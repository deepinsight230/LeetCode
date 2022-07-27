class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> copy=nums;
        sort(copy.begin(), copy.end());
        int n=nums.size(), k=0;
        for(int i=1;i<n;i=i+2) nums[i]=copy[n-1-(k++)];
        for(int i=0;i<n;i+=2) nums[i]=copy[n-1-(k++)];
    }
};