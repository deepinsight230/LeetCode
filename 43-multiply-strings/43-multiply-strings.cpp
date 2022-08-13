class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        // reverse(num2.begin(), num2.end());
        // int n1=num1.size(), n2=num2.size();
        // if(n1<n2){
        //     int diff=n2-n1;
        //     string append(diff, '0');
        //     num1=append+num1;
        // }
        // else if(n2<n1){
        //     int diff=n1-n2;
        //     string append(diff, '0');
        //     num2=append+num2;
        // }
        int n1=num1.size(), n2=num2.size();
        string ans="";
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
        // cout<<num1<<" "<<num2<<endl;
        // cout<<ans<<endl;
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n1=num1.size(), n2=num2.size();
        string ans="";
        for(int i=0;i<n1;i++){
            int dig1=num1[i]-'0';
            string temp="";
            int carry=0;
            for(int j=0;j<n2;j++){
                int dig2=num2[j]-'0';
                int mul=(dig1*dig2);
                temp+=('0'+((mul+carry)%10));
                carry=(mul+carry)/10;
            }
            if(carry!=0) temp+=('0'+carry);
            string append(i, '0');
            append+=temp;
            // cout<<append<<endl;
            ans=addStrings(ans, append);
            // cout<<ans<<endl;
        }
        return ans;
    }
};