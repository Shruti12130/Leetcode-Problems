class Solution {
public:
    
    void dfs(int node, vector<int> &vis, vector<int>& values, int &maxTime, 
            int &ans, int time, int quality, vector<pair<int, int>> adj[]) {
        if(time > maxTime) {
            return;
        }
        if(vis[node]==0) {
            quality+=values[node];
        }
        vis[node]++;
        if(node == 0) {
            ans=max(ans, quality);
        }
        
        for(auto it: adj[node]) {
            int adjNode = it.first;
            int timeTaken = time+it.second;
            dfs(adjNode, vis, values, maxTime, ans, timeTaken, quality, adj);
        }
        vis[node]--;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<pair<int, int>> adj[n+1];
        for(auto it: edges) {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> vis(n+1, 0); 
        int ans=values[0], time=0, quality=0;
        dfs(0, vis, values, maxTime, ans, time, quality, adj);
        return ans;
    }
};