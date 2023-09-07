class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n, 0);
        ans[n-1]=0;
        stack<int> st;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--) {
            int c=1;
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                c+=ans[st.top()];
                st.pop();
            }
            ans[i] = st.empty() ? 0 : c;
            st.push(i);
        }
        return ans;
    }
};