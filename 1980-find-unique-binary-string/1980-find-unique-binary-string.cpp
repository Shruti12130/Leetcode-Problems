class Solution {
public:
    unordered_set<string> st;
    string ans;
    void solve(int i, int n, string value) {
        if(value.length()==n) {
            if(st.find(value)==st.end()) {
                ans=value;
            }
            return;
        }
        
        for(int j=i;j<n;j++) {
            if(ans.size()==n) {
                return;
            }
            solve(j+1, n, value+"0");
            solve(j+1, n, value+"1");
        }
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto it: nums) {
            st.insert(it);
        }
        solve(0,  nums[0].length(), "");
        return ans;
    }
};