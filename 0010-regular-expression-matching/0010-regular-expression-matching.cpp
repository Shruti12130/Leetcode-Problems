class Solution {
public:
    int dp[21][21];
    
    bool solve(int n, int m, string &s, string &p) {
        if(n==0 && m==0) {
            return true;
        }
        if(n>0 && m<=0) {
            return false;
        }
        if(n<=0 && m>0) {
            int i=m;
            while(i) {
                if(p[i-1]=='*') {
                    i-=2;
                } else {
                    return false;
                }
            }
            return true;
        }
        
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(s[n-1]==p[m-1] || p[m-1]=='.') {
            return dp[n][m] = solve(n-1, m-1, s, p);
        }
        if(p[m-1]=='*'){
            if(s[n-1]!=p[m-2] && p[m-2]!='.') {
                return dp[n][m] = solve(n, m-2, s, p);
            }
            return dp[n][m] = solve(n-1, m, s, p) || solve(n, m-2, s, p);
        }
        return dp[n][m] = false;
    }
    
    bool isMatch(string s, string p) {
        int n=s.length(), m=p.length();
        memset(dp, -1, sizeof(dp));
        return solve(n, m, s, p);
    }
};