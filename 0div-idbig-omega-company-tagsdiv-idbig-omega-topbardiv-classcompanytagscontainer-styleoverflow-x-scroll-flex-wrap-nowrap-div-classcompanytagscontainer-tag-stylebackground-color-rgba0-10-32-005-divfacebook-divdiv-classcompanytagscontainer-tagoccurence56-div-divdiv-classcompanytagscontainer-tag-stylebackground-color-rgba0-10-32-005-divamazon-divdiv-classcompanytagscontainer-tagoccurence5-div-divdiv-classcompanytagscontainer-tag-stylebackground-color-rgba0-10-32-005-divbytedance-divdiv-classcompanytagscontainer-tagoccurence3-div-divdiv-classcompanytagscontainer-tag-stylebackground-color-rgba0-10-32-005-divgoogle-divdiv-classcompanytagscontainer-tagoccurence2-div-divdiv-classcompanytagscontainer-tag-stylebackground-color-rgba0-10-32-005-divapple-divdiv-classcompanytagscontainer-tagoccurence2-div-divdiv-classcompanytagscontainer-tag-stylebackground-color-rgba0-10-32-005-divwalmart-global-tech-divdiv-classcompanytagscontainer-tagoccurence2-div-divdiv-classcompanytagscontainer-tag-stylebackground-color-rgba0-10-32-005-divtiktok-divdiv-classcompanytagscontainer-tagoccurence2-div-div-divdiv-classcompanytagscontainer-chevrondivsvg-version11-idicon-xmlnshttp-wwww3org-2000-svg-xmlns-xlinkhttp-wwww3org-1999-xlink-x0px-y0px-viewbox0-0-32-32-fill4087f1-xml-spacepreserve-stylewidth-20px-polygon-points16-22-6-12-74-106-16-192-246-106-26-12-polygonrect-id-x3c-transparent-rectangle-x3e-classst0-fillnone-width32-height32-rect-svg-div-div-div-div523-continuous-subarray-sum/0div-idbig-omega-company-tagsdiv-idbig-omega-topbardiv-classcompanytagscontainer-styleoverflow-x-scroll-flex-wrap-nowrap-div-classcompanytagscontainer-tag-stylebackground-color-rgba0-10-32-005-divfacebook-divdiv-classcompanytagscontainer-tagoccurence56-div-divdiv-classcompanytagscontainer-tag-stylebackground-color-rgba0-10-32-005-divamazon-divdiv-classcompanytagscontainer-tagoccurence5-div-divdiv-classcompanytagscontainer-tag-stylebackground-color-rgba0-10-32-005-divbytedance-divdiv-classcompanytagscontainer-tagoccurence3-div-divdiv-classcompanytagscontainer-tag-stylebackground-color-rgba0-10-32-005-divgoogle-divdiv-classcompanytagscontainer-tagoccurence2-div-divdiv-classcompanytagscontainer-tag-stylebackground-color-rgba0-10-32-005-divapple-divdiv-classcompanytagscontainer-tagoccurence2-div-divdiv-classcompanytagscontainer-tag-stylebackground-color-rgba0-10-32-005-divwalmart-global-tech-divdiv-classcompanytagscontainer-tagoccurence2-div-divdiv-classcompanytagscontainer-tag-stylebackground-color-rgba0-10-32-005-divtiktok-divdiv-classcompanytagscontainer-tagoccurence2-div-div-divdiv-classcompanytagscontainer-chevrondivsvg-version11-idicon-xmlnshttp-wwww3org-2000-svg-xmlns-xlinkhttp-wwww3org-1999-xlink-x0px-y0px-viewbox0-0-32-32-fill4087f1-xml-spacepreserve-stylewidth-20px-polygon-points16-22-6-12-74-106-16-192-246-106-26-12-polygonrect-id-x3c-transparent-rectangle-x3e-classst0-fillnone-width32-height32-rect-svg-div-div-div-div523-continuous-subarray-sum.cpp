class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0, ans=0, sum=0;
        unordered_map<int, int> mp;
        
        for(int j=0;j<n;j++) {
            sum+=nums[j];
            if(j>0 && sum%k==0) {
                return 1;
            }
            if(mp.count(sum%k) && j-mp[sum%k]>=2) {
                return 1;
            }
            if(mp.count(sum%k)==0) {
                mp[sum%k]=j;
            }
        }
        return 0;
    }
};