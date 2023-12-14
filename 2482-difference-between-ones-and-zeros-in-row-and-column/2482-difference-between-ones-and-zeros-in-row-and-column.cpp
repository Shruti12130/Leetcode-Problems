class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<int> onesRow(n), onesCol(m), zerosRow(n), zerosCol(m);
        for(int i=0;i<n;i++) {
            int ones=0;
            for(int j=0;j<m;j++) {
                if(grid[i][j]) {
                    ones++;
                }
            }
            onesRow[i]=ones;
            zerosRow[i]=m-ones;
        }
        
        for(int j=0;j<m;j++) {
            int ones=0;
            for(int i=0;i<n;i++) {
                if(grid[i][j]) {
                    ones++;
                }
            }
            onesCol[j]=ones;
            zerosCol[j]=n-ones;
        }
        
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int val=onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
                ans[i][j]=val;
            }
        }
        return ans;
    }
};