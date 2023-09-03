class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i, int sum, int k, int n, vector<int> temp) {
        if(temp.size()==k) {
            if(sum==n) {
                ans.push_back(temp);
            }
            return;
        }
        
        for(int j=i;j<=9;j++) {
            if(sum+j<=n) {
                temp.push_back(j);
                solve(j+1, sum+j, k, n, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(1, 0, k, n, temp);
        return ans;
    }
};