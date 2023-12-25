class Solution {
public:
    int dp[102];
    
    int findNoOfWays(int i, string &s) {
        int n = s.length();
        if(i==n) {
            return 1;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        if(s[i]=='0') {
            return dp[i]=0;
        }
        int ans=findNoOfWays(i+1, s);
        //For str = "10" to "26"
        if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) {
            ans+=findNoOfWays(i+2, s);
        }
        return dp[i]=ans;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return findNoOfWays(0, s);
    }
};