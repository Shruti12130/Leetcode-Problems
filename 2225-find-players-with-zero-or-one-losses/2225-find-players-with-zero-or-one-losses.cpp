class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        for(auto it: matches) {
            mp[it[1]]++;
        }
        vector<vector<int>> ans;
        vector<int> temp1, temp2;
        set<int> t1, t2;
        for(auto it: matches) {
            int i=it[0], j=it[1];
            if(mp[i]==0) {
                t1.insert(i);
            } else if(mp[i]==1) {
                t2.insert(i);
            }
            if(mp[j]==0) {
                t1.insert(j);
            } else if(mp[j]==1) {
                t2.insert(j);
            }
        }
        for(auto it: t1) temp1.push_back(it);
        for(auto it: t2) temp2.push_back(it);
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};