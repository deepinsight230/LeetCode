class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i: nums) pq.push(i);
        while(k--){
            int temp=pq.top();
            pq.pop();
            pq.push(++temp);
        }
        long long ans=1;
        while(!pq.empty()){
            int temp=pq.top();
            pq.pop();
            ans=(ans*temp)%1000000007;
        }
        return (ans%1000000007);
    }
};