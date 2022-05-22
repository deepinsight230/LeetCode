class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end());
        long ans=1;
        int n=stockPrices.size();
        if(n==1) return 0;
        if(n==2) return 1;
        long long num=(stockPrices[1][0]-stockPrices[0][0]);
        long long deno=(stockPrices[1][1]-stockPrices[0][1]);
        long double prev=0;
        if(deno!=0) prev=(long double)num/(double)deno;
        // cout<<prev;
        for(int i=0;i<n-1;i++){
            num=(stockPrices[i+1][0]-stockPrices[i][0]);
            deno=(stockPrices[i+1][1]-stockPrices[i][1]);
            // cout<<i<<" "<<num<<" "<<deno<<" "<<prev<<endl;
            if(deno==0){
                if(prev!=0){
                    ans++;
                    prev=0;
                    continue;
                }
                else{
                    prev=0; continue;
                }
            }
            long double curr=(long double)num/(double)deno;
            // cout<<i<<" "<<curr<<" "<<ans<<endl;
            if(curr==prev) continue;
            else if(curr!=prev){
                prev=curr;
                ans++;
            }
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};