class Solution {
public:
    int dp[2501][2501], n;
    
    int solve(int curr, int prev, vector<int> &nums) {
        if(curr>=n) {
            return 0;
        }
        if(dp[curr][prev+1]!=-1) {
            return dp[curr][prev+1];
        }
        int take=0, dontTake=solve(curr+1, prev, nums);
        if(prev==-1 || nums[curr] > nums[prev]) {
            take = 1+solve(curr+1, curr, nums);
        }
        return dp[curr][prev+1] = max(take, dontTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }
};