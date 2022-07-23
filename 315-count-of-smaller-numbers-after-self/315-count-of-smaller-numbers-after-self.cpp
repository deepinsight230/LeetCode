#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long 
#define ull unsigned long long
#define ui unsigned int
#define D double
#define ld long double
#define ff first
#define ss second
#define Q(n) queue <n>
#define ST(n) stack <n>
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ppf pop_front()
#define ppb pop_back()
#define mp(n,m) make_pair(n,m)
#define umap(a,b) unordered_map<a,b>
#define uset(a) unordered_set<a>
#define pqb priority_queue<long long int>
#define pqs priority_queue<int, vll, greater<long long int>>
#define vll vector<long long>
#define vi vector<int>
#define ts(n) to_string(n)
#define f(var1,start,end) for(int var1=start;var1<end;var1++)
#define loopitr(var1,start,end,it) for(int var1=start;var1<end;var1+=it)
#define rf(var2,start,end) for(int var2=start;var2>=end;var2--)
#define odd(n) (n&1)
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define mod 1000000007
//#define mod 998244353
#define PI 3.141592653589793238462
#define show(ans) cout<<ans<<endl;
#define showY cout<<"YES"<<endl;
#define showN cout<<"NO"<<endl;
// *st.find_by_order(x); => this will return an iterator to the element at index x;
// st.order_of_key(x);=> this will return count of elements that are strictly less than x;

using namespace std;
using namespace __gnu_pbds;

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
//calculate factorial of n
ll fact(ll n){
    ll res=1;
    for(ll i=1;i<=n;i++) res=(res*i)%mod;
    return res;
}
//input an array
void input(vector<ll> &vec,ll n){
    ll temp,i;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.pb(temp);
    }
}
//calculate modulo inverse
ll modulo_inverse(ll n){  
    return pow(n,mod-2);
}
//calculate combination nCr
ll nCr(ll n,ll r){
    if (r==0 || n==0) return 1;
    ll fac[n+1];
    fac[0]=1;
    ll i;
    for(int i=1;i<=n;i++)
        fac[i]=(fac[i-1]*i)%mod;
    return (fac[n]*modulo_inverse(fac[r])%mod*modulo_inverse(fac[n-r])%mod)%mod;
}
//Function to find n^k
ll power(ll x,ll y)
{
    if(y == 0)
        return 1;
    ll p=power(x,y/2);
    if(y % 2 == 0)
        return (p%mod * p)%mod;
    else
        return (x * p%mod * p)%mod;
}

//check whether the no is prime or not
bool isprime(ll n){
    ll i;
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(i=3;i*i<=n;i+=2)
        if(n%i==0) return false;
    return true;
}
//covert binary(string) to decimal(ll)
ll decimal(string s){
    reverse(s.begin(),s.end());
    ll ans=0,i=1,j=0;
    while(j<s.size()){
        if(s[j]=='1'){
            ans+=i;
        }
        i*=2;
        j++;
    }
    return ans;
}
//convert decimal(ll) to binary(string)
string binary(ll n){
    string temp;
    if(n==0) return "0";
    while(n){
        temp+=to_string(n%2);
        n/=2;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=size(nums);
        pbds s;
        vi ans;
        rf(i, n-1, 0){
            s.insert(nums[i]);
            ans.pb(s.order_of_key(nums[i]));
        }
        reverse(all(ans));
        return ans;
    }
};