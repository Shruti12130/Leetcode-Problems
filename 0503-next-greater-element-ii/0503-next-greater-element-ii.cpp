class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(nums[n-1]);
        
        for(int i=2*n-1;i>=0;i--) {
            while(!st.empty() && nums[i%n]>=st.top()) {
                st.pop();
            }
            ans[i%n] = st.empty() ? -1 : st.top();
            st.push(nums[i%n]);
        }
        return ans;
    }
};