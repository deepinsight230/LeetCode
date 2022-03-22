class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int l=0, e=0, g=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) e++, g++;
            else if(nums[i]==pivot) g++;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) ans[l++]=nums[i];
            else if(nums[i]==pivot) ans[e++]=nums[i];
            else ans[g++]=nums[i];
        }
        return ans;
    }
};