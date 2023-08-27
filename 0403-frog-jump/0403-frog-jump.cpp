class Solution {
public:
    int dp[2001][2001];
    unordered_map<int, int> mp;
    
    bool solve(int ind, int prev, int n, vector<int> &stones) {
        if(ind==n-1) {
            return 1;
        }
        
        if(dp[ind][prev]!=-1) {
            return dp[ind][prev];
        }
        bool ans=0;
        int x=stones[ind]+prev-1;
        int y=stones[ind]+prev;
        int z=stones[ind]+prev+1;
        
        if(x>stones[ind] && mp.find(x) != mp.end()) {
            ans |= solve(mp[x], prev-1, n, stones);
        }
        if(y>stones[ind] && mp.find(y) != mp.end()) {
            ans |= solve(mp[y], prev, n, stones);
        }
        if(z>stones[ind] && mp.find(z) != mp.end()) {
            ans |= solve(mp[z], prev+1, n, stones);
        }
        return dp[ind][prev]=ans;
    }
    
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=1) {
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++) {
            mp[stones[i]]=i;
        }
        return solve(1, 1, n, stones);
    }
};