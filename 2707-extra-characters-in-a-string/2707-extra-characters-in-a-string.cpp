class Solution {
public:
    
    int dp[51];
    
    int solve(string s, unordered_set<string> &st) {
        int n=s.length();
        if(n==0) {
            return 0;
        }
        if(dp[n]!=-1) {
            return dp[n];
        }
        int ans=INT_MAX;
        
        for(int i=1;i<=n;i++) {
            string word=s.substr(0, i);
            int k=solve(s.substr(i), st);
            if(st.count(word)) {
                ans=min(ans, k);
            } else {
                ans=min(ans, k+i);
            }
        }
        return dp[n]=ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        unordered_set<string> st{dictionary.begin(), dictionary.end()};
        memset(dp, -1, sizeof(dp));
        return solve(s, st);
    }
};