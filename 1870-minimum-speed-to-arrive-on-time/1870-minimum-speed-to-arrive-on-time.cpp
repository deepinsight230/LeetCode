class Solution {
public:
    bool isValid(int mid, vector<int> &dist, double hour){
        double cnt=0;
        int n=dist.size();
        for(int i=0;i<n;i++){
            if(i==(n-1)) cnt+=(dist[i]/(mid*1.00));
            else cnt+=ceil(dist[i]/(mid*1.00));
            // cout<<i<<" "<<(dist[i]/mid*1.00)<<endl;
        }
        return (cnt<=hour);
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        for(int i=0;i<dist.size();i++){
            if(hour<=((dist.size()-1)*1.00)) return -1;
        }
        int low=1, high=INT_MAX, ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            cout<<mid<<endl;
            if(isValid(mid, dist, hour)){
                ans=min(ans, mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};