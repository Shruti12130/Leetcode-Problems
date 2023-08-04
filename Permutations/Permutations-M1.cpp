class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    
    void solve(vector<int> &temp, vector<int> &nums) {
        int n = nums.size();
        if(temp.size()==n) {
            ans.push_back(temp);
            return;
        }
        
        for(int k=0;k<n;k++) {
            if(!mp[nums[k]]) {
                temp.push_back(nums[k]);
                mp[nums[k]]++;
                solve(temp, nums);
                mp[nums[k]]--;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(temp, nums);
        return ans;
    }
};
