class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size(), m=mat[0].size();
        vector<pair<int, int>> v;
        int c=0;
        for(int i=0;i<n;i++) {
            int f=0;
            for(int j=0;j<m;j++) {
                if(mat[i][j]==0) {
                    v.push_back({j+1, i});
                    c=i+1;
                    f=1;
                    break;
                }
            }
            if(!f) {
                v.push_back({m+1, c++});
            }
        }
        sort(v.begin(), v.end());
        vector<int> ans(k);
        for(int i=0;i<k;i++) {
            ans[i]=v[i].second;
        }
        return ans;
    }
};