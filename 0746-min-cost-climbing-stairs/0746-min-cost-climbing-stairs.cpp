class Solution {
public:
    int dp[1001], n;
    
    int solve(int i, vector<int>& cost) {
        if(i>=n){
            return 0;
        }
        if(dp[i]!=INT_MAX-1) {
            return dp[i];
        }
        return dp[i]=cost[i]+min(solve(i+1, cost), solve(i+2, cost));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        for(int i=0;i<=n;i++) {
            dp[i]=INT_MAX-1;
        }
        return min(solve(0, cost), solve(1, cost));
    }
};