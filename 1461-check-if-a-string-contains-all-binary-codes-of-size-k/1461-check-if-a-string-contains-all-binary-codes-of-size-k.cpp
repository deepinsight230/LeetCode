class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int i=0, j=0;
        string str="";
        while(j<s.size()){
            str+=s[j];
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                // cout<<str<<endl;
                st.insert(str);
                str=str.substr(1);
                j++;
                i++;
            }
        }
        int num=pow(2, k);
        if(st.size()==num) return true;
        else return false;
    }
};