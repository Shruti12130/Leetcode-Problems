class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    int n;
    
    void solve(int ind, vector<int> temp, vector<int> &nums) {
        if(ind==n) {
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }
        
        solve(ind+1, temp, nums);
        temp.push_back(nums[ind]);
        solve(ind+1, temp, nums);
        temp.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        vector<int> temp;
        solve(0, temp, nums);
        for(auto it: st) {
            ans.push_back(it);
        }
        return ans;
    }
};