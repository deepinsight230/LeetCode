class Solution {
public:
    int nextValidDay(int i, vector<int> &days){
        int low=0, high=days.size()-1, ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(days[mid]==i) return i;
            if(days[mid]>i){
                ans=days[mid];
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int helper(int i, int tdays, vector<int>& days, vector<int>& costs, vector<int> &dp){
        if(i>tdays) return 0;
        i=nextValidDay(i, days);
        if(dp[i]!=-1) return dp[i];
        int temp;
        temp=costs[0]+helper(i+1, tdays, days, costs, dp);
        temp=min(temp, costs[1]+helper(i+7, tdays, days, costs, dp));
        temp=min(temp, costs[2]+helper(i+30, tdays, days, costs, dp));
        return dp[i]=temp;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(days[n-1]+1, -1);
        return helper(days[0], days[n-1], days, costs, dp);
    }
};