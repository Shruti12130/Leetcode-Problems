class Solution {
public:
    vector<int> nextSmallerELementOnRight(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(n);
        ans[n-1]=n-1;
        stack<int> st;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--) {
            while(!st.empty() && heights[i]<=heights[st.top()]) {
                st.pop();
            }
            ans[i] = st.empty() ? n-1 : st.top()-1;
            st.push(i);
        }
        
        return ans;
    }
    
    vector<int> nextSmallerELementOnLeft(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(n);
        ans[0]=0;
        stack<int> st;
        st.push(0);
        
        for(int i=1;i<n;i++) {
            while(!st.empty() && heights[i]<=heights[st.top()]) {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : st.top()+1;
            st.push(i);
        }
        
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftHeight = nextSmallerELementOnLeft(heights);
        vector<int> rightHeight = nextSmallerELementOnRight(heights);
        int ans=0;
        
        for(int i=0;i<n;i++) {
            ans = max(ans, heights[i]*(rightHeight[i]-leftHeight[i]+1));
        }
        return ans;
    }
};