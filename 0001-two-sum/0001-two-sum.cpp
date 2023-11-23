class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) {
            int pair=target-nums[i];
            if(mp.find(pair)!=mp.end()) {
                return {mp[pair], i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};