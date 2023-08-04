class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    
    void solve(int ind, vector<int> &nums) {
        int n = nums.size();
        if(ind==n) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<n;i++) {
            swap(nums[ind], nums[i]);
            solve(ind+1, nums);
            swap(nums[ind], nums[i]);  //backtrack, i.e., undo the changes done before the recursive call
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};
