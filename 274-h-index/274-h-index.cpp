class Solution {
public:
    bool isValid(int mid, vector<int>& citations){
        int cnt=0;
        for(int i=citations.size()-1;i>=0;i--){
            if(citations[i]>=mid) cnt++;
            if(cnt>=mid) return true;
        }
        return false;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=0, high=n, ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(mid, citations)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};