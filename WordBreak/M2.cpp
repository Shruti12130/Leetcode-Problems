class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        vector<bool> dp(n+1, 0);
        dp[0]=1;
        
        for(int i=1;i<=n;i++) {
            for(int j=0;j<i;j++) {
                string word = s.substr(j, i-j);
                if(st.count(word)) {
                    if(dp[j]) {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};
