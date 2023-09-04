class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mp;
        mp[0]++;
        int sum=0, ans=0, x=0;
        
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            x=sum%k;
            if(x<0) {
                x+=k;
            } 
            if(mp.find(x)!=mp.end()) {
                ans+=mp[x];
            }
            mp[x]++;
        }
        return ans;
    }
};