class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size(), sum=0;
        for(int i=0;i<m;i++){
            sum+=rolls[i];
        }
        int num=((mean*(m+n))-sum);
        if(num<=0) return {};
        vector<int> ans(n);
        while(n){
            if(num<=0) return {};
            double x=((num*1.0)/(n*1.0));
            if(ceil(x)>6.0){ cout<<x; return {};}
            ans[--n]=ceil(x);
            num-=x;
            
        }
        return ans;
    }
};