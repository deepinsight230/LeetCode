class Solution {
public:
    void sieveBuild(vector<long long> &sieve, int n){
        sieve[0]=sieve[1]=1;
        for(long long i=2;i<=(n/2);i++){
            if(sieve[i]==-1){
                for(long long j=i*i;j<=n;j+=i){
                    sieve[j]=1;
                }
            }
        }
    }
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<long long> sieve(n+1, -1);
        sieveBuild(sieve, n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(sieve[i]==-1) ans++;
        }
        return ans;
    }
};