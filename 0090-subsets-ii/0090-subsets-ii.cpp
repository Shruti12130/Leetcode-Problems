class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void solve(int ind, vector<int> temp, vector<int> &nums) {
        ans.push_back(temp);
        
        for(int i=ind;i<n;i++) {
            if(i>ind && nums[i]==nums[i-1]) {
                continue;
            }
            
            temp.push_back(nums[i]);
            solve(i+1, temp, nums);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, temp, nums);
        return ans;
    }
};