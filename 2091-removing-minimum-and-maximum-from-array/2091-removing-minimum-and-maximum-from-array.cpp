class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mx=max_element(nums.begin(), nums.end())-nums.begin();
        int mn=min_element(nums.begin(), nums.end())-nums.begin();
        if(mn>mx) swap(mn, mx);
        int c1=mx+1;
        int c2=n-mn;
        int c3=(mn+1)+(n-mx);
        return min(min(c1, c2), c3);
    }
};