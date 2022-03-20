class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int mn=INT_MAX, cnt, tcnt, bcnt;
        bool flag=false;
        for(int i=1;i<=6;i++){
            cnt=0, tcnt=0, bcnt=0;
            for(int j=0;j<n;j++){
                if(tops[j]==i) tcnt++;
                if(bottoms[j]==i) bcnt++;
                if(tops[j]==i||bottoms[j]==i) cnt++;
                if(tops[j]!=i&&bottoms[j]!=i) break;
            }
            // cout<<i<<" "<<cnt<<endl;
            if(cnt==n){
                flag=true;
                mn=min(mn, n-max(tcnt, bcnt));
            }
        }
        if(flag==true) return mn;
        return -1;
    }
};