class Solution {
public:
    
    void dfs(int i, vector<bool> &vis, vector<int> adj[]) {
        vis[i] = 1;
        for(auto it: adj[i]) {
            if(!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) {
            return -1;
        }
        int cnt = 0;
        vector<int> adj[n+1];
        for(auto it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n+1, 0);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt-1;
    }
};