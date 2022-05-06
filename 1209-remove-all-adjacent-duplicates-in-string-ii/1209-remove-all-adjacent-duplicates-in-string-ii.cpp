class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char ch: s){
            if(st.empty()) st.push({ch, 1});
            else{
                auto pr=st.top();
                if(ch==pr.first){
                    st.pop();
                    st.push({ch, pr.second+1});
                }
                else st.push({ch, 1});
                if(st.top().second==k) st.pop();
            }
        }
        string ans="";
        while(!st.empty()){
            auto pr=st.top();
            // cout<<pr.second<<" "<<pr.first<<endl;
            ans.append(pr.second, pr.first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};