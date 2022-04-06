class Solution {
public:
    long long ways(int n,int r)
    {   
        if(n==r)
            return 1;
       if(r==1)
           return n;
        long long p = 1, k = 1;
 
   
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
      
            long long m = __gcd(p, k);
 
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
    }
         else
        p = 1;
        return p;
    }
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>count(101,0);
        
        for(int i=0;i<n;i++)
        {
            count[arr[i]]++;
        }
        long long sum=0;
        for(int i=0;i<n-2;i++)
        {
            if(i!=0 && arr[i]==arr[i-1])
                continue;
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(arr[i]+arr[j]+arr[k]<target)
                    j++;
                else if(arr[i]+arr[j]+arr[k]>target)
                    k--;
                else
                {
                 if(arr[i]==arr[j] && arr[j]==arr[k])
                 {
                     sum=sum+(ways(count[arr[i]],3))%1000000007;
                 }
                    else if(arr[i]==arr[j] || arr[j]==arr[k] || arr[k]==arr[i])
                    {
                        if(arr[i]==arr[j])
                        {
                            sum=sum+((ways(count[arr[i]],2)%1000000007 * (ways(count[arr[k]],1))%1000000007));
                        }
                        else if(arr[j]==arr[k])
                        {
                            sum=sum+(ways(count[arr[j]],2))%1000000007 *(ways(count[arr[i]],1))%1000000007;
                        }
                        else
                        {
                             sum=sum+(ways(count[arr[i]],2))%1000000007 *(ways(count[arr[j]],1))%1000000007;
                        }
                    }
                    else
                    {
                        sum=sum+((ways(count[arr[i]],1))%1000000007 *(ways(count[arr[j]],1))%1000000007 *(ways(count[arr[k]],1))%1000000007) ;
                    }
                    j=j+1;
                    k=k-1;
                    while(arr[j]==arr[j-1] && j<k)
                        j++;
                      while(arr[k]==arr[k+1] && j<k)
                        k--;
                }
            }
        }
        return sum;
    }
};