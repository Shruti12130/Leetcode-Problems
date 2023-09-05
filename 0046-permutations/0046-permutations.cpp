class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void solve(int ind, vector<int> & nums) {
        if(ind==n) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<n;i++) {
            swap(nums[ind], nums[i]);
            solve(ind+1, nums);
            swap(nums[ind], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        solve(0, nums);
        return ans;
    }
};