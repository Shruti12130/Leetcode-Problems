class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n+1];
        unordered_map<string, int> mp;
        for(auto it: roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            string s1 = to_string(it[0]) + "," + to_string(it[1]);
            string s2 = to_string(it[1]) + "," + to_string(it[0]);
            mp[s1]++, mp[s2]++;
        }
        
        int mx=-1;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int k = adj[i].size() + adj[j].size();
                string s = to_string(i) + "," + to_string(j);
                if(mp.count(s) != 0) {
                    k--;
                }
                mx = max(mx, k);
            }
        }
        return mx;
    }
};