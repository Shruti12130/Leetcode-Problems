class Solution {
public:
    int mod=1e9+7;
    int dp[31][1001];
    
    int solve(int n, int k, int target) {
        if(target==0 && n==0) {
            return 1;
        }
        if(n<0 || target<0) {
            return 0;
        }
        if(dp[n][target]!=-1) {
            return dp[n][target];
        }
        long long ans=0;
        for(int i=k;i>=1;i--) {
            if(i>target) {
                continue;
            }
            ans=ans+(solve(n-1, k, target-i)%mod)%mod;
        }
        return dp[n][target]=ans%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target)%mod;
    }
};