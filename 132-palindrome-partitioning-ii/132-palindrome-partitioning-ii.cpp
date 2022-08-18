#define ll long long
class Solution {
public:
    bool isPalindrome(int l, int r, string &s){
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++, r--;
        }
        return true;
    }
    ll helper(int l, int r, string &s, vector<int> &dp){
        if(l>r) return 0;
        if(dp[l]!=-1) return dp[l];
        ll mn=10e12;
        for(int i=l;i<=r;i++){
            if(isPalindrome(l, i, s)) mn=min(mn, 1+helper(i+1, r, s, dp));
        }
        return dp[l]=mn;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n, -1);
        return helper(0, n-1, s, dp)-1;
    }
};