class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        int mx=0;
        for(auto it: nums) {
            mp[it]++;
            mx=max(mx, mp[it]);
        }
        
        vector<vector<int>> ans(mx);
        for(auto it: mp) {
            auto [num, freq] = it;
            for(int i=0;i<freq;i++) {
                ans[i].push_back(num);
            }
        }
        return ans;
    }
};