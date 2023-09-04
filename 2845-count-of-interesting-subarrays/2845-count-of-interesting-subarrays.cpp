class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        long long sum=0, x=0, ans=0;
        
        unordered_map<long long, long long> mp;
        for(int i=0;i<n;i++) {
            sum += (nums[i] % modulo == k);
            x = sum % modulo;
            if(x == k) {
                ans++;
            }
            int neg = x - k;
            if(neg < 0) {
                neg += modulo;
            }
            ans += mp[neg];
            mp[x]++;
        }
        return ans;
    }
};