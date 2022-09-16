class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l=0, r=tokens.size()-1;
        sort(tokens.begin(), tokens.end());
        int ans=0, score=0;
        while(l<=r){
            bool flag=false;
            while(l <= r && tokens[l] <= power){
                power-=tokens[l];
                score++;
                ans=max(ans, score);
                l++;
                flag=true;
            }
            if(l<=r && score >= 1){
                power+=tokens[r];
                score--;
                r--;
                flag=true;
            }
            if(!flag) return ans;
        }
        return ans;
    }
};