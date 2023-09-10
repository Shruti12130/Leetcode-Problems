class Solution {
public:
    int solve(vector<vector<int>> &grid) {
        bool flag=true;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(grid[i][j]!=1) {
                    flag=false;
                    break;
                }
            }
        }
        if(flag) {
            return 0;
        }
        
        int ans=INT_MAX;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                for(int x=0;x<3;x++) {
                    for(int y=0;y<3;y++) {
                        if(grid[i][j]==0 && grid[x][y]>1) {
                            grid[x][y]--;
                            grid[i][j]++;
                            
                            int dis=abs(i-x)+abs(j-y);
                            ans=min(ans, dis+solve(grid));
                            
                            grid[i][j]--;
                            grid[x][y]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        return solve(grid);
    }
};