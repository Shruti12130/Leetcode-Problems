class Solution {
public:
    int dp[2001][2001];
    int n, m;
    
    bool solve(int i, int j, string &s, string &p) {
        if(i==n && j==m) {
            return 1;
        }  
        if(i<=n && j>=m) {
            return 0;
        } 
        if(i>=n && j<=m) {
            for(int x=j;x<m;x++) {
                if(p[x] != '*')
                    return 0;
            }
            return 1;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?') {
            return dp[i][j]=solve(i+1, j+1, s, p);
        } 
        if(p[j]=='*') {
            return dp[i][j] = solve(i+1, j, s, p) || solve(i, j+1, s, p);
        }
        return dp[i][j] = 0;
    }
    
    bool isMatch(string s, string p) {
        n=s.length(), m=p.length();
        memset(dp, -1, sizeof(dp));
        if(m==1 && p=="*") {
            return 1;
        }
        return solve(0, 0, s, p);
    }
};
