class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size(), m=mat[0].size();
        vector<pair<int, int>> vec(n);
        vector<int> ans(k);
        
        for(int i=0;i<n;i++){
            vec[i].first=0;
            for(int j=0;j<m;j++){
                vec[i].first+=mat[i][j];
                vec[i].second=i;
            }
        }
        sort(vec.begin(), vec.end());
        for(int i=0;i<k;i++){
            ans[i]=vec[i].second;
        }
        return ans;
    }
};