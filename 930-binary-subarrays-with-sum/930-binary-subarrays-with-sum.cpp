class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int n=nums.size(), psum=0, ans=0;
        if(goal==0){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]==1){
                    ans+=(cnt*(cnt+1)/2);
                    cnt=0;
                }
                else{
                    cnt++;
                }
            }
            ans+=(cnt*(cnt+1)/2);
            return ans;
        }
        mp[0]=1;
        for(int i=0;i<n;i++){
            psum+=(nums[i]==1)?1:0;
            mp[psum]++;
        }
        
        for(auto m: mp){
            int key=m.first;
            int req=(goal+key);
            // cout<<key<<" "<<req<<endl;
            // cout<<mp[key]<<" "<<mp[req]<<endl;
            if(mp.find(req)!=mp.end()){
                ans+=mp[key]*mp[req];
            }
        }
        return ans;
    }
};