#define mod 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int evens=0, odds=0, psum=0, ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            psum+=arr[i];
            if(psum%2==0){
                ans=(ans+odds)%mod;
                evens++;
            }
            else{
                ans=(ans+evens+1)%mod;
                odds++;
            }
        }
        return ans;
    }
};