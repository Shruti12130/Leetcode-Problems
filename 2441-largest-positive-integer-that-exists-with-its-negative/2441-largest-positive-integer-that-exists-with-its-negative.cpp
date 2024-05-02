class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            if(nums[i]>0) {
                if(mp.count(-1*nums[i])) {
                    ans=max(ans, nums[i]);
                }
            }
        }
        return ans==0 ? -1 : ans;
    }
};