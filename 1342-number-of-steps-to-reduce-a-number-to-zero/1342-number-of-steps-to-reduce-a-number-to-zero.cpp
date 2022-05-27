class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        while(num){
            ans++;
            if(num&1) num--;
            else num/=2;
        }
        return ans;
    }
};