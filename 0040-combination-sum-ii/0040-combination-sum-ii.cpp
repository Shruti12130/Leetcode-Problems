class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void solve(int ind, int sum, int target, vector<int>temp, vector<int> &candidates){
        if(sum==target) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind;i<n;i++) {
            if(i>ind && candidates[i]==candidates[i-1]) {
                continue;
            }
            if(sum+candidates[i] > target) {
                break;
            }
            temp.push_back(candidates[i]);
            solve(i+1, sum+candidates[i], target, temp, candidates);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, 0, target, temp, candidates);
        
        return ans;
    }
};