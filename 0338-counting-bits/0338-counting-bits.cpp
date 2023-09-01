class Solution {
public:
    int dp[100001];
    
    int solve(int n) {
        if(n==0 || n==1) {
            return n;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        if(n%2==0) {
            return dp[n]=solve(n/2);
        } else {
            return dp[n]=1+solve(n/2);
        }
    }
    
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<=n;i++) {
            ans[i]=solve(i);
        }
        return ans;
    }
};