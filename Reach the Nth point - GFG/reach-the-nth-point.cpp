// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int helper(int n, vector<int> &dp){
	    if(n==0||n==1)  return 1;
		if(dp[n]!=-1) return dp[n];
		return dp[n]=((helper(n-1, dp)+helper(n-2, dp))%1000000007);
	}
		int nthPoint(int n){
		    // Code here
		    vector<int> dp(n+1, -1);
		    return helper(n, dp);
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends