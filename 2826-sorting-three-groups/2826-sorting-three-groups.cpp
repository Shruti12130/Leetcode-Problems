class Solution {
public:
    int dp[101][101];
    
    int solve(int idx, int prev, vector<int> &nums) {
        int n=nums.size();
        if(idx==n) {
            return 0;
        }
        if(dp[idx][prev] != -1) {
            return dp[idx][prev];
        }
        int mn=INT_MAX, curr=nums[idx];
        for(int i=prev;i<=3;i++) {
            int next=solve(idx+1, i, nums);
            if(i != curr) {
                next++;
            }
            mn=min(mn, next);
        }
        return dp[idx][prev]=mn;
    }
    
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, nums);
    }
};