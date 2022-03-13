class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable=0, curr=0;
        while(curr<nums.size()-1){
            reachable=max(reachable, curr+nums[curr]);
            if(reachable<=curr) return false;
            curr++;
        }
        return (reachable>=nums.size()-1);
    }
};