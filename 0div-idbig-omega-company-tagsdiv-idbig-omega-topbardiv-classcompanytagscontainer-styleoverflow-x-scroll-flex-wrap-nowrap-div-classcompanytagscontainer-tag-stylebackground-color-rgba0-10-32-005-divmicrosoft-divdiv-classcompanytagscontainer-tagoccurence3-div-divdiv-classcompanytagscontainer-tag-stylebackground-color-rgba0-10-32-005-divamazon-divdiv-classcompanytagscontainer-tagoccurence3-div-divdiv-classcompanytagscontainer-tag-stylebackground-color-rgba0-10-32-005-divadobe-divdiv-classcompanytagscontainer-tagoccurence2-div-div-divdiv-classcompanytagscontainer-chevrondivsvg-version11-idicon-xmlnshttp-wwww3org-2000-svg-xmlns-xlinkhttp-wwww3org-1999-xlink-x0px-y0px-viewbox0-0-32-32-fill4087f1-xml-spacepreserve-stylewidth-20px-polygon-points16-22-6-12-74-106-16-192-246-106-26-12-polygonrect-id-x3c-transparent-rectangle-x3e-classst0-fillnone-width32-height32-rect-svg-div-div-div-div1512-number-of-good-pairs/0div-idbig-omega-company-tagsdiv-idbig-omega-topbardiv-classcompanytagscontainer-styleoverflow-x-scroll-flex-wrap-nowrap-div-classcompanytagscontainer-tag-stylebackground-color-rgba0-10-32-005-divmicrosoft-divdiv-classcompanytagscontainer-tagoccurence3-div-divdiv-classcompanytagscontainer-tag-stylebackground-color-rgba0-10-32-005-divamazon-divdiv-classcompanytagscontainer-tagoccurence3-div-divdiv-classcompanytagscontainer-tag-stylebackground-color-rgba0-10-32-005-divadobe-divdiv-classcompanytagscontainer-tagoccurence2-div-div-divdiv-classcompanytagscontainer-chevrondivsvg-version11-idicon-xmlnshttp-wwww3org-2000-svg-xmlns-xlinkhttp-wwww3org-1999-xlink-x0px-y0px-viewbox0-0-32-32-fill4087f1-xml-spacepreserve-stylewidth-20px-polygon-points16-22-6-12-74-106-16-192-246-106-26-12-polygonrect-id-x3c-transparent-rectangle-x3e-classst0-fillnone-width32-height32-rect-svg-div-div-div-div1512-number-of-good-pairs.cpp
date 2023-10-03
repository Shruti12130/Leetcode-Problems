class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto it: mp) {
            if(it.second>1) {
                int k=it.second;
                k=(k*(k-1))/2;
                ans+=k;
            }
        }
        return ans;
    }
};