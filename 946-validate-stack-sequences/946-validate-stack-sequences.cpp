class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j=0;
        for(int i=0;i<popped.size();){
            if(j>=pushed.size()) break;
            while(s.empty()||s.top()!=popped[i]){
                if(j>=pushed.size()) break;
                s.push(pushed[j++]);
            }
            while(!s.empty()&&i<popped.size()&&s.top()==popped[i]){
                s.pop();
                i++;
            }
        }
        return (s.empty());
    }
};