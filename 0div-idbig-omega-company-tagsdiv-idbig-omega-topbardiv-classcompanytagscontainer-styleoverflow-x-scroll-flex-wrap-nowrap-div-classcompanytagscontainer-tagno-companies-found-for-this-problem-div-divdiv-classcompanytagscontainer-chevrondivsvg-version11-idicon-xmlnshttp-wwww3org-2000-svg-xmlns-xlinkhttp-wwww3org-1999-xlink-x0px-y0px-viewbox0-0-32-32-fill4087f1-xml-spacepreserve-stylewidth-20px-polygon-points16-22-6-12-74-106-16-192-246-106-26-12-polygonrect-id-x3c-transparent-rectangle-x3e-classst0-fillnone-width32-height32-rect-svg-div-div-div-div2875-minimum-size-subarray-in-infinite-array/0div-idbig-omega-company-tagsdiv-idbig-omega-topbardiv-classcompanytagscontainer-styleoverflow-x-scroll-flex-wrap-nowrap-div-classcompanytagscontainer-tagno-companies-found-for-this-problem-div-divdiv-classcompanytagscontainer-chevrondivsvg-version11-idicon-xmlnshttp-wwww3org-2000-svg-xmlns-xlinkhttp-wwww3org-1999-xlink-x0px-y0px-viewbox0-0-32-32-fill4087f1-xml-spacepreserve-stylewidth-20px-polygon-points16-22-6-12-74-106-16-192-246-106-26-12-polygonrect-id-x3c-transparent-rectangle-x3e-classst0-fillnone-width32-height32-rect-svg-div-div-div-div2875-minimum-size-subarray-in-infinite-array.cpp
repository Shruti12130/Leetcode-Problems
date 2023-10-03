class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n=nums.size();
        long long totalSum=accumulate(nums.begin(), nums.end(), 0LL);
        long long count=0;
        
        if(totalSum < target) {
            int noOfFullSubarrays = target/totalSum;
            count = n * noOfFullSubarrays;
            int k = target % totalSum;
            if(k==0) {
                return count;
            } else {
                target = k;
            }
        }
        
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        unordered_map<long long, int> mp;
        long long currSum=0;
        int ans=INT_MAX;
        
        for(int i=0;i<2*n;i++) {
            currSum+=nums[i];
            if(currSum==target) {
                ans=min(ans, i+1);
            } else if(mp.find(currSum-target) != mp.end()) {
                ans=min(ans, i-mp[currSum-target]);
            }
            mp[currSum] = i;
        }
        
        return (ans==INT_MAX) ? -1 : ans+count;
    }
};