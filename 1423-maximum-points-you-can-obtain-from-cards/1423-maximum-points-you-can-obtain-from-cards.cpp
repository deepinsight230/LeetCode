class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int n=points.size(), i=0, j=0;
        if(n==k) return accumulate(points.begin(), points.end(), 0);
        k=n-k;
        int ans=INT_MAX, sum=0;
        while(j<n){
            sum+=points[j];
            if((j-i +1) == k){
                ans=min(ans, sum);
                sum-=points[i];
                i++;
            }
            j++;
        }
        sum=accumulate(points.begin(), points.end(), 0);
        return sum-ans;
    }
};