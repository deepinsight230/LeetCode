class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(target!=1){
            ans++;
            if(maxDoubles>0){
                if(target&1) target--;
                else{
                    maxDoubles--;
                    target>>=1;
                }
            }
            else{
                ans+=(target-2);
                break;
            }
            cout<<target<<endl;
        }
        return ans;
    }
};