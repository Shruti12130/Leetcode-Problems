class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        int n=A.size(), m=A[0].size();
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(A[i][j]==0) {
                    v.push_back({i, j});
                }
            }
        }
        for(auto it: v) {
            int p=it.first, q=it.second;
            for(int i=0;i<n;i++) {
                A[i][q]=0;
            }
            for(int i=0;i<m;i++) {
                A[p][i]=0;
            }
        }
    }
};