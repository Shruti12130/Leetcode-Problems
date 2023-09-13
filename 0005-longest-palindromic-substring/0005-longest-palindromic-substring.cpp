class Solution {
public:
    int dp[1001][1001];
    
    bool solve(int i, int j, string &s, int &mx, int &idx) {
        if(i>=j) {
            return true;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i]==s[j]) {
            dp[i][j] = solve(i+1, j-1, s, mx, idx);
        } else {
            dp[i][j] = 0;
        }
        if(dp[i][j]) {
            if(mx<(j-i+1)) {
                mx=j-i+1;
                idx=i;
            }
        }
        return dp[i][j];
    }
    
    string longestPalindrome(string s) {
        int n=s.length();
        memset(dp, -1, sizeof(dp));
        int mx=1, idx=0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                solve(i, j, s, mx, idx);
            }
        }
        return s.substr(idx, mx);
    }
};