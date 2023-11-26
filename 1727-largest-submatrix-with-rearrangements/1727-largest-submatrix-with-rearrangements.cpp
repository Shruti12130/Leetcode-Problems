class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        int ans=0;
        
        for(int i=0;i<m;i++) {  //Iterating over columns
            for(int j=1;j<n;j++) {   //Iterating over rows
                if(matrix[j][i]==1) {
                    matrix[j][i]+=matrix[j-1][i];
                }
            }
        }
        
        for(auto &it: matrix) {
            sort(it.rbegin(), it.rend());
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans=max(ans, matrix[i][j]*(j+1));
            }
        }
        return ans;
    }
};