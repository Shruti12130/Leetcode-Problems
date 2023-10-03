class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) {
            return (nums[0]==k);
        }
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++) {
            pre[i]=pre[i-1]+nums[i];
        }
        int i=0, ans=0;
        unordered_map<int, int> mp;
        for(int j=0;j<n;j++) {
            if(pre[j]==k) {
                ans++;
            }
            if(mp.find(pre[j]-k)!=mp.end()) {
                ans+=mp[pre[j]-k];
            }
            mp[pre[j]]++;
        }
        return ans;
    }
};