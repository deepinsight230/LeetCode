class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0, n=gas.size();
        for(int i=0;i<n;i++) sum+=gas[i]-cost[i];
        if(sum<0) return -1;
        int start=0; sum=0;
        for(int i=0;i<n;i++){
            sum+=gas[i]-cost[i];
            // cout<<i<<" "<<sum<<endl;
            if(sum<0){
                sum=0;
                start=i+1;
            }
        }
        return start;
    }
};