class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        for(auto it: paths) {
            mp[it[0]]=it[1];
        }
        for(auto it: paths) {
            string cityA=it[0], cityB=it[1];
            if(mp.find(cityA)==mp.end()) {
                return cityA;
            }
            if(mp.find(cityB)==mp.end()) {
                return cityB;
            }
        }
        return "";
    }
};