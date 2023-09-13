class Solution {
public:
    int dp[1001][1001];
    
    int solve(int n, int m, string &a, string &b) {
        if(n<=0 && m<=0) {
            return 0;
        }
        if(n<=0 || m<=0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(a[n-1]==b[m-1]) {
            return dp[n][m] = 1+solve(n-1, m-1, a, b);
        } else {
            return dp[n][m] = max(solve(n-1, m, a, b), solve(n, m-1, a, b));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string x=s;
        reverse(x.begin(), x.end());
        memset(dp, -1, sizeof(dp));
        return solve(n, n, s, x);
    }
};