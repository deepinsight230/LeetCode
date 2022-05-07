class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> mn(n);
        mn[0]=nums[0];
        for(int i=1;i<n;i++) mn[i]=min(mn[i-1], nums[i]);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=mn[i]) st.pop();
            if(!st.empty()){
                if(st.top()>mn[i]&&st.top()<nums[i]) return true;
            }
            st.push(nums[i]);
        }
        return false;
    }
};