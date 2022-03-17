class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pair<int, int>> q;
        q.push({arr[start], start});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int val=q.front().first;
                int idx=q.front().second;
                q.pop();
                if(val<0) continue;
                if(val==0) return true;
                if(idx-val>=0) q.push({arr[idx-val], idx-val}) ;
                if(idx+val<arr.size()) q.push({arr[idx+val], idx+val});
                arr[idx]=-val;
            }
        }
        return false;
    }
};