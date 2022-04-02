class Solution {
public:
    bool isPal(int i, int j, string s){
        while(i<j){
            if(s[i]==s[j]) i++, j--;
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0, j=s.size()-1;
        bool flag=true;
        while(i<j){
            if(s[i]==s[j]) i++, j--;
            else{
                return (isPal(i+1, j, s)||isPal(i, j-1, s))? true: false;
            }
        }
        return true;
    }
};