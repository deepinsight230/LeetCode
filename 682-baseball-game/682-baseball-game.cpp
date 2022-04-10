class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int i=0;
        for(string ch: ops){
            if(ch=="+"){
                int n1=s.top(); s.pop();
                int n2=s.top(); s.pop();
                s.push(n2); s.push(n1);
                s.push(n1+n2);
            }
            else if(ch=="D"){
                int n=s.top();
                s.push(2*n);
            }
            else if(ch=="C"){
                s.pop();
            }
            else{
                s.push(stoi(ch));
            }
            i++;
        }
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};