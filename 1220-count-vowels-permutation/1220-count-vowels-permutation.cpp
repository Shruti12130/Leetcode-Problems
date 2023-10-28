class Solution {
public:
    int countVowelPermutation(int n) {
        int mod=1e9+7;
        long long ans=0LL;
        vector<vector<int>> dp(n+1, vector<int> (5, 0));
        for(int i=0;i<5;i++) {
            dp[1][i]=1;
        }
        
        vector<vector<int>> mp = {{1,2,4}, {0,2}, {1,3}, {2}, {2,3}};
        
        for(int i=2;i<=n;i++) {
            for(int j=0;j<5;j++) {
                for(auto it: mp[j]){
                    dp[i][j] = (dp[i][j]+dp[i-1][it])%mod;
                }
            }
        }
        for(int i=0;i<5;i++) {
            ans=(ans+dp[n][i])%mod;
        }
        return (int)ans;
    }
};