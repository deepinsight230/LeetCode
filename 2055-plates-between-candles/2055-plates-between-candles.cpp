class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size(), q=queries.size();
        vector<int> ans(q, 0);
        vector<int> prefix(n, 0);
        prefix[0]=(s[0]=='*')?0:1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+((s[i]=='*')?0:1);
        }
        // for(int i=0;i<n;i++) cout<<prefix[i]<<" ";
        for(int i=0;i<q;i++){
            int l=queries[i][0], r=queries[i][1], ll, rr;
            if(s[l]=='*') ll=prefix[l]+1;
            else ll=prefix[l];
            rr=prefix[r];
            int ff=lower_bound(prefix.begin(), prefix.end(), ll)-prefix.begin();
            int ss=lower_bound(prefix.begin(), prefix.end(), rr)-prefix.begin();
            // cout<<ff<<" "<<ss<<endl;
            // cout<<ll<<" "<<rr<<endl;
            int len=(ss-ff+1); 
            ans[i]=max(0, len-(rr-ll+1));
        }
        return ans;
    }
};