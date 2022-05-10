class Solution {
public:
    int search(int target, vector<pair<int, int>> &job){
        int ans=0;
        int low=0, high=job.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(job[mid].first<=target){
                ans=max(ans, job[mid].second);
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m=profit.size(), n=worker.size();
        vector<pair<int, int>> job(m);
        int ans=0;
        for(int i=0;i<m;i++){
            job[i].second=profit[i];
            job[i].first=difficulty[i];
        }
        sort(job.begin(), job.end());
        int maxp=job[0].second;
        for(int i=1;i<m;i++){
            maxp=max(maxp,job[i].second);
            job[i].second=maxp;
        }
        for(int i=0;i<m;i++) cout<<job[i].first<<" "<<job[i].second<<endl;
        for(int i=0;i<n;i++){
            ans+=search(worker[i], job);
        }
        return ans;
    }
};