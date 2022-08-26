class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> nums;
        while(n){
            nums.push_back(n%10);
            n/=10;
        }
        sort(nums.begin(), nums.end());
        do{
            if(nums[0]==0) continue;
            int num=0;
            for(int i=0;i<nums.size();i++) num=num*10+nums[i];
            // cout<<num<<endl;
            bool temp=true;
            while(num&&temp){ 
                // cout<<num<<endl;
                if((num&1) == 1) temp=false;
                num=num>>1;
            }
            if(num==0) return true;
        }while(next_permutation(nums.begin(), nums.end()));
        return false;
    }
};