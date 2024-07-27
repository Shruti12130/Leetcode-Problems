class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> adj(26, vector<int>(26, 1e9));
        for(int i=0;i<26;i++) {
            adj[i][i]=0;
        }
        
        for(int i=0;i<original.size();i++) {
            int from=original[i]-'a', to=changed[i]-'a';
            adj[from][to] = min(adj[from][to], cost[i]);
        }
        
        //Floyd Warshall Algorithm
        for(int k=0;k<26;k++) {
            for(int i=0;i<26;i++) {
                if(adj[i][k] < 1e9) {
                    for(int j=0;j<26;j++) {
                        adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                    }
                }
            }
        }
        
        long long ans=0;
        for(int i=0;i<source.size();i++) {
            if(source[i]==target[i]) {
                continue;
            }
            int from=source[i]-'a', to=target[i]-'a';
            if(adj[from][to]==1e9) {
                return -1;
            }
            ans+=adj[from][to];
        }
        return ans;
    }
};