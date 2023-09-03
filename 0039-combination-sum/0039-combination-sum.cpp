class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void solve(int ind, int sum, int target, vector<int> temp, vector<int> &candidates) {
        if(ind==n) {
            if(sum==target) {
                ans.push_back(temp);
            }
            return;
        }
        
        if(sum+candidates[ind] <= target) {
            temp.push_back(candidates[ind]);
            solve(ind, sum+candidates[ind], target, temp, candidates);
            temp.pop_back();
        } 
        solve(ind+1, sum, target, temp, candidates);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int> temp;
        solve(0, 0, target, temp, candidates);
        return ans;
    }
};