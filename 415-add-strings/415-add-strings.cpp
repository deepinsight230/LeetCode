class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans="";
        int n1=num1.size(), n2=num2.size();
        int i=0, carry=0;
        while(i<n1 && i<n2){
            int add=(num1[i]-'0')+(num2[i]-'0')+carry;
            ans+=('0'+add%10);
            carry=add/10;
            i++;
        }
        while(i<n1){
            int add=(num1[i]-'0')+carry;
            ans+=('0'+add%10);
            carry=add/10;
            i++;
        }
        while(i<n2){
            int add=(num2[i]-'0')+carry;
            ans+=('0'+add%10);
            carry=add/10;
            i++;
        }
        if(carry!=0) ans+=('0'+carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};