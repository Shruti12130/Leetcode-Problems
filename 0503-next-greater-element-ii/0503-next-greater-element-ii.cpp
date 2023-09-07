class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        int k=2*n;
        vector<int> arr=nums;
        arr.insert(arr.end(), nums.begin(), nums.end());
        vector<int> ans(k);
        ans[k-1]=-1;
        stack<int> st;
        st.push(arr[k-1]);
        
        for(int i=k-2;i>=0;i--) {
            while(!st.empty() && arr[i]>=st.top()) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        ans.erase(ans.begin()+n, ans.end());
        return ans;
    }
};