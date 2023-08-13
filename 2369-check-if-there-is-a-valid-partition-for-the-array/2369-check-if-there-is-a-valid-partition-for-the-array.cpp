class Solution {
public:
    int dp[100001];
    
    int solve(int n, vector<int> &nums) {
        if(n==0 || (n==2 && nums[0]==nums[1])) {
            return true;
        } 
        if(dp[n] != -1) {
            return dp[n];
        }
        
        if(n-3>=0 && nums[n-1]==nums[n-2] && nums[n-2]==nums[n-3]) {
            return dp[n] = solve(n-2, nums) || solve(n-3, nums);
        } else if(n-2>=0 && nums[n-1]==nums[n-2]) {
            return dp[n] = solve(n-2, nums);
        } else {
            if(n-3>=0 && nums[n-1]-nums[n-2]==1 && nums[n-2]-nums[n-3]==1) {
                return dp[n] = solve(n-3, nums);
            }
        }
        return dp[n] = false;
    }
    
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(n, nums);
    }
};