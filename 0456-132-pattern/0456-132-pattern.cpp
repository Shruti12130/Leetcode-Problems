class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) {
            return false;
        }
        int mn[n];
        mn[0]=nums[0];
        for(int i=1;i<n;i++) {
            mn[i]=min(mn[i-1], nums[i]);
        }
        
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            if(nums[i] > mn[i]) {
                while(!st.empty() && st.top()<=mn[i]) {
                    st.pop();
                }
                if(!st.empty() && nums[i] > st.top()) {
                    return true;
                }
            }
            st.push(nums[i]);
        }
        
        return false;
    }
};