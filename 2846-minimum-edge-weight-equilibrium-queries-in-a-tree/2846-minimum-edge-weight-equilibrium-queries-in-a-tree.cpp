class Solution {
public:
    int log;
    int count[10001][27];
    vector<vector<int>> dp;
    
    void dfs(int u, int p, int log, vector<int> &lev, vector<pair<int, int>> adj[]) {
        dp[u][0]=p;
        for(int i=1;i<=log;i++) {
            dp[u][i] = dp[dp[u][i-1]][i-1];
        }
        
        for(auto it: adj[u]) {
            if(it.first != p) {
                lev[it.first]=lev[u]+1;
                dfs(it.first, u, log, lev, adj);
            }
        }
    }
    
    int lca(int u, int v, int log, vector<int> &lev) {
        if(lev[u] < lev[v]) {
            swap(u, v);
        }
        
        for(int i=log;i>=0;i--) {
            if((lev[u]-pow(2, i)) >= lev[v]) {
                u=dp[u][i];
            }
        }
        
        if(u==v) {
            return u;
        }
        
        for(int i=log;i>=0;i--) {
            if(dp[u][i] != dp[v][i]) {
                u=dp[u][i];
                v=dp[v][i];
            }
        }
        return dp[u][0];
    }
    
    void getCount(int n, int par, vector<pair<int, int>> adj[]) {
        for(int i=0;i<=26;i++) {
            count[n][i] += count[par][i];
        }
        
        for(auto it: adj[n]) {
            if(it.first!=par) {
                count[it.first][it.second]++;
                getCount(it.first, n, adj);
            }
        }
    }
     
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        memset(count, 0, sizeof(count));
        vector<pair<int, int>> adj[n+1];
        for(auto it: edges) {
            int a=it[0], b=it[1], c=it[2];
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        getCount(0, 0, adj);
        log=32;
        dp.assign(n+1, vector<int>(log+1, -1));
        vector<int> lev(n+1);
        
        dfs(0, 0, log, lev, adj);
        
        int q=queries.size();
        vector<int> ans(q);
        int x=0;
        while(q--) {
            int u=queries[x][0], v=queries[x][1];
            int l = lca(u, v, log, lev);
            int temp=0, mx=0;
            for(int i=0;i<=26;i++) {
                int curr = count[u][i] + count[v][i] - 2*count[l][i];
                temp+=curr;
                mx = max(mx, curr);
            }
            ans[x]=temp-mx;
            
            x++;
        }
        return ans;
    }
};