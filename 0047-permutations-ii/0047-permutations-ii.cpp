class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void solve(int ind, vector<int> nums) {
        if(ind==n) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<n;i++) {
            if(i>ind && nums[i]==nums[ind]) {
                continue;
            }
            swap(nums[ind], nums[i]);
            solve(ind+1, nums);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return ans;
    }
};