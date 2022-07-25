class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(true){
            s.insert(n);
            int temp=n, sum=0;
            while(temp){
                int rem=temp%10;
                sum+=rem*rem;
                temp/=10;
            }
            n=sum;
            if(n==1) return true;
            if(s.find(n)!=s.end()) return false;
        }
    }
};