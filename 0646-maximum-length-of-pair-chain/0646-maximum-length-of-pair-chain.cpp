class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        int ans = 1, curr = pairs[0][1];
        for(auto it: pairs) {
            if(curr < it[0]) {
                ans++;
                curr = it[1];
            }
        }
        return ans;
    }
};