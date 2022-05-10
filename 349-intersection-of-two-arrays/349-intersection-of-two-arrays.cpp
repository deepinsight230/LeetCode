class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, n1=nums1.size(), n2=nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        while(i<n1&&j<n2){
            while(i<n1-1&&nums1[i]==nums1[i+1]) i++;
            while(j<n2-1&&nums2[j]==nums2[j+1]) j++;
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++, j++;
            }
            else{
                if(nums1[i]<nums2[j]) i++;
                else j++;
            }
        }
        return ans;
    }
};