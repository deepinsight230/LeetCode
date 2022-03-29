class Solution {
public:
    bool isValid(vector<int> &nums, int m, int mid){
        int cnt=1, prev=0;
        for(int i=1;i<nums.size(); i++){
            if((nums[i]-nums[prev])>=mid){
                cnt++;
                prev=i;
            }
        }
        return (cnt>=m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n=position.size();
        int low=1, high=(position[n-1]-position[0]), ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(position, m, mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};