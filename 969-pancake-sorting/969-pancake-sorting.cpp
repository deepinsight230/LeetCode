class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        int curr=n;
        while(curr){
            int idx=find(arr.begin(), arr.end(), curr)-arr.begin();
            ans.push_back(idx+1);
            ans.push_back(curr);
            curr--;
            reverse(arr.begin(), arr.begin()+idx+1);
            reverse(arr.begin(), arr.begin()+curr+1);
        }
        return ans;
    }
};