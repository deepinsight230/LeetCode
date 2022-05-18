class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0, open=0;
        for(char ch: s){
            if(ch==')'&&open==0) cnt++;
            else if(ch==')'&&open>0) open--;
            else if(ch=='(') open++;
        }
        return cnt+open;
    }
};