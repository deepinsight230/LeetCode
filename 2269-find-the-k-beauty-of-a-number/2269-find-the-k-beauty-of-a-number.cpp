class Solution {
public:
    int divisorSubstrings(int number, int k) {
        vector<int> nums;
        int temp=number;
        while(temp!=0){
            int rem=temp%10;
            nums.push_back(rem);
            temp/=10;
        }
        reverse(nums.begin(), nums.end());
        int i=0, j=0, cnt=0;
        int num=0;
        while(j<nums.size()){
            num=num*10+nums[j];
            if(j-i+1<k) j++;
            else{
                // cout<<num<<endl;
                if(num!=0&&number%num==0) cnt++;
                int div=pow(10, k-1);
                if(k>1) num=num%div;
                else num=0;
                i++, j++;
            }
        }
        return cnt;
    }
};