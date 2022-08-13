class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n1=num1.size(), n2=num2.size();
        vector<int> arr(n1+n2, 0);
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                mul+=arr[i+j+1];
                arr[i+j+1]=(mul%10);
                arr[i+j]+=mul/10;
            }
        }
        string ans="";
        bool flag=false;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0) flag=true;
            if(flag) ans+=('0'+arr[i]);
        }
        return (ans=="")?"0":ans;
    }
};