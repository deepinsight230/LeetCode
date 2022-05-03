class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr;
        arr=nums;
        bool flag=false;
        int s=1, l=0;
        sort(arr.begin(), arr.end());
        for(int i=0;i<nums.size();i++){
            if(arr[i]!=nums[i]){
                if(flag==false) flag=true, s=i;
                l=i;
            }
        }
        return (l-s+1);
    }
};