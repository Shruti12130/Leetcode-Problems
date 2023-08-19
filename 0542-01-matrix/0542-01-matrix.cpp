class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        
        queue<array<int, 3>> q;
        
        int row=-1, col=-1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]==0) {
                    ans[i][j] = 0;
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()) {
            auto [i, j, dist] = q.front();
            q.pop();
            
            for(auto it: dirs) {
                int x = i+it.first;
                int y = j+it.second;
                
                if(x>=0 && y>=0 && x<n && y<m && !vis[x][y]) {
                    vis[x][y] = 1;
                    ans[x][y] = dist+1;
                    q.push({x, y, ans[x][y]});
                }
            }
        }
        return ans;
    }
};