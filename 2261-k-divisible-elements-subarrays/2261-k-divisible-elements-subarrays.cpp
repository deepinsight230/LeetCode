class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        unordered_set<string> s;
        for(int i=0;i<n;i++){
            string str="";
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]%p==0) cnt++;
                if(cnt<=k) str+=to_string(nums[j])+" ";
                else break;
                s.insert(str);
            }
        }
        return s.size();
    }
};