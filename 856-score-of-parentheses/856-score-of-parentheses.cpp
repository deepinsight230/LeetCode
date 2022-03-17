class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth=0, ans=0;
        char prev;
        for(char ch: s){
            if(ch=='('){
                depth++;
            }
            else{
                depth--;
                if(prev=='(') ans+=pow(2, depth);
            }
            prev=ch;
        }
        return ans;
    }
};