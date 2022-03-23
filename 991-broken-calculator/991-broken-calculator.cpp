class Solution {
public:
    int brokenCalc(int sV, int target) {
        int ans=0;
        while(sV!=target){
            ans++;
            if(sV>target||target&1) target++;
            else target/=2;
        }
        return ans;
    }
};