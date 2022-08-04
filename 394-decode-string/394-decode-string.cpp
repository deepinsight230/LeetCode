class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans="";
        for(char ch: s){
            if(ch!=']') st.push(ch);
            else{
                string temp="";
                while(st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                string num="";
                while(!st.empty() && st.top()<='9' && st.top()>='0'){
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());
                int n=stoi(num);
                while(n--){
                    for(char ch: temp) st.push(ch);
                }
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};