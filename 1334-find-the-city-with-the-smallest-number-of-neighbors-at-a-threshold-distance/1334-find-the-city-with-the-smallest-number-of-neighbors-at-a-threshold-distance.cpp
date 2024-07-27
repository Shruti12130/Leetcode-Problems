class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n+1, vector<int>(n+1, 1e9));
        for(int i=0;i<n;i++) {
            adj[i][i]=0;
        }
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]][edges[i][1]]=min(adj[edges[i][0]][edges[i][1]], edges[i][2]);
            adj[edges[i][1]][edges[i][0]]=min(adj[edges[i][1]][edges[i][0]], edges[i][2]);
        }
        
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        vector<vector<int>> neighbors(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i!=j && adj[i][j]<=distanceThreshold) {
                    neighbors[i].push_back(j);
                } 
            }
        }
        int minNum=1e9;
        for(int i=0;i<n;i++) {
            int x=neighbors[i].size();
            minNum=min(minNum, x);
        }
        int ans=n-1;
        for(int i=n-1;i>=0;i--) {
            if(neighbors[i].size()==minNum) {
                ans=i;
                break;
            }
        }
        return ans;
    }
};