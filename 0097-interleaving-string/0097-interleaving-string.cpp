class Solution {
public:
    int dp[101][101][201];
    
    bool isInterleaved(int n, int m, int k, string a, string b, string c) {
        if(n==0 && m==0 && k==0) {
            return 1;
        } else {
            if(n==0) {
                return c.substr(0, k) == b.substr(0, m);
            } else if(m==0) {
                return a.substr(0, n) == c.substr(0, k);
            } 
        }
        
        if(dp[n][m][k] != -1) {
            return dp[n][m][k];
        }
        if(c[k-1]==a[n-1] && c[k-1] == b[m-1]) {
            return dp[n][m][k] = isInterleaved(n-1, m, k-1, a, b, c) || 
                                 isInterleaved(n, m-1, k-1, a, b, c);
        } else if(c[k-1]==a[n-1]) {
            return dp[n][m][k] = isInterleaved(n-1, m, k-1, a, b, c);
        } else if(c[k-1] == b[m-1]) {
            return dp[n][m][k] = isInterleaved(n, m-1, k-1, a, b, c);
        } else {
            return dp[n][m][k] = 0;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(), m=s2.length(), k=s3.length();
        if(k!=n+m) {
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        return isInterleaved(n, m, k, s1, s2, s3);
    }
};