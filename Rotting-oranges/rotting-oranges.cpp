class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), cnt=0;
        queue<array<int, 3>> q;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({i, j, 0});
                } else if(grid[i][j]==1) {
                    cnt++;
                }
            }
        }
        if(cnt==0) {
            return 0;
        }
        int ans=0, c=0;
        
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto [i, j, dist] =q.front();
                q.pop();

                for(int k=0;k<4;k++) {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1) {
                        q.push({x, y, dist+1});
                        grid[x][y]=2;
                        c++;
                    }
                }
            }
            ans++;
        }
        return c==cnt ? ans-1 : -1;
    }
};
