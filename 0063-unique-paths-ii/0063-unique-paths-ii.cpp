static int t[101][101];

class Solution {
public:
    
    int uniquePath(int n, int m, vector<vector<int>>& obstacleGrid) {
        if(n < 0 || m < 0 || obstacleGrid[n][m] == 1) {
            return 0;
        }
        if(n == 0 && m == 0) {
            return 1;
        }
        if(t[n][m] != -1) {
            return t[n][m];
        }
        return t[n][m] = uniquePath(n-1, m, obstacleGrid) + 
                         uniquePath(n, m-1, obstacleGrid);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        memset(t, -1, sizeof(t));
        return uniquePath(n-1, m-1, obstacleGrid);
    }
};