class Solution {
public:
    int countVowelPermutation(int n) {
        int mod=1e9+7;
        long long ans=0LL;
        vector<vector<int>> dp(n+1, vector<int> (5, 0));
        for(int i=0;i<5;i++) {
            dp[1][i]=1;
        }
        unordered_map<int, vector<int>> mp;
        mp[0]={1,2,4};
        mp[1]={0,2};
        mp[2]={1,3};
        mp[3]={2};
        mp[4]={2,3};
        
        for(int i=2;i<=n;i++) {
            for(int j=0;j<5;j++) {
                for(auto it: mp[j]){
                    int k=it;
                    (dp[i][j]+=dp[i-1][k]%mod)%=mod;
                }
            }
        }
        for(int i=0;i<5;i++) {
            (ans+=dp[n][i]%mod)%=mod;
        }
        return (int)ans%mod;
    }
};