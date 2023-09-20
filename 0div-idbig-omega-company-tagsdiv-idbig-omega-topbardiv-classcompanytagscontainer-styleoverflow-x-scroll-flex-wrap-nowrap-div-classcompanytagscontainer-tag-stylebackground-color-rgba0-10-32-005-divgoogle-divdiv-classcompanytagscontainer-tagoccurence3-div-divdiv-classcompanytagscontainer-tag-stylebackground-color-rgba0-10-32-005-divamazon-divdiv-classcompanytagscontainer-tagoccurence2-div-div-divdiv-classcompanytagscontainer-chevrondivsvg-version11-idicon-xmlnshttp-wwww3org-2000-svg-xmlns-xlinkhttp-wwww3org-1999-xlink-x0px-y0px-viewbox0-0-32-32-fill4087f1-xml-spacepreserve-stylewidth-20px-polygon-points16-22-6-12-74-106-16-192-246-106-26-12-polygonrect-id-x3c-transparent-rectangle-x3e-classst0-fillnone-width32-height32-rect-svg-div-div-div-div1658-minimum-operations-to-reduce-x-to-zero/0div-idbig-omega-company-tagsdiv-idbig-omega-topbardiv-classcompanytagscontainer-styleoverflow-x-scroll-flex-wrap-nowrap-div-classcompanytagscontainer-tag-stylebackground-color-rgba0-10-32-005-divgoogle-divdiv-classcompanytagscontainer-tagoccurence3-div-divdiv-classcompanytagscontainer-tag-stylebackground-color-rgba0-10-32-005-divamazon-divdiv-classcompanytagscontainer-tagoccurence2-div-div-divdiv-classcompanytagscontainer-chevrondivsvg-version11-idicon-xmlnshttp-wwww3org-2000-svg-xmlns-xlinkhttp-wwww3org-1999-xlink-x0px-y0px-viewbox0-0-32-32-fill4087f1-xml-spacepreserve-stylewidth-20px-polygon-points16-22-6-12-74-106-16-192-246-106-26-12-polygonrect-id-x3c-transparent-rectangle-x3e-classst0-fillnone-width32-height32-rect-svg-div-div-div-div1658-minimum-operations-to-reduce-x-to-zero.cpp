class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int, int> mp;
        int prefixsum=0, suffixsum=0, ans=INT_MAX;
        for(int i=0;i<n;i++) {
            prefixsum+=nums[i];
            if(prefixsum==x) {
                ans=min(ans, i+1);
            }
            mp[prefixsum]=i+1;
        }
        
        for(int i=n-1;i>=0;i--) {
            suffixsum+=nums[i];
            if(suffixsum==x) {
                ans=min(ans, n-i);
            }
            if(mp[x-suffixsum]>0 && i+1>mp[x-suffixsum]) {
                ans=min(ans, (n-i)+mp[x-suffixsum]);
            }
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};