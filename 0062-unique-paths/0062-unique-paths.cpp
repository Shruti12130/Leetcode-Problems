class Solution {
public:
    int dp[101][101];
    
    int uniquePath(int n, int m) {
        if(n < 0 || m < 0) {
            return 0;
        }
        if(n == 0 && m == 0) {
            return 1;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        return dp[n][m] = uniquePath(n-1, m) + uniquePath(n, m-1);
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return uniquePath(n-1, m-1);
    }
};