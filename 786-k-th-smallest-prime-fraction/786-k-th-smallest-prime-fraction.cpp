#define info pair<double, pair<int, int>>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<info> fractions;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                fractions.push_back({(double)arr[i]/arr[j], {arr[i], arr[j]}});
            }
        }
        priority_queue<info> pq;
        for(auto x: fractions){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans(2);
        ans[0]=pq.top().second.first;
        ans[1]=pq.top().second.second;
        return ans;
    }
};