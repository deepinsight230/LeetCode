class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums, temp;
        int num2=num;
        while(num){
            int rem=num%10;
            nums.push_back(rem);
            num/=10;
        }
        reverse(nums.begin(), nums.end());
        temp=nums;
        sort(temp.begin(), temp.end(), greater<int>());
        // for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
        int i, j;
        for(i=0;i<nums.size();i++)
            if(nums[i]!=temp[i]) break;
        if(i==nums.size()) return num2;
        for(j=nums.size()-1;j>=0;j--){
            if(nums[j]==temp[i]) break;
        }
        swap(nums[i], nums[j]);
        num=0;
        for(int i=0;i<nums.size();i++)
            num=num*10+nums[i];
        return num;
    }
};