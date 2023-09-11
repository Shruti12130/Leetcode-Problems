class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>> ans;
        vector<pair<int, int>> v(n);
        
        for(int i=0;i<n;i++) {
            v[i]={groupSizes[i], i};
        }
        sort(v.begin(), v.end());
        for(int i=0;i<n;) {
            vector<int> temp;
            int k=v[i].first, c=0;
            while(i<n && c<k) {
                temp.push_back(v[i].second);
                i++;
                c++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};