class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=n-1, ans=0;
        sort(nums.begin(), nums.end());
        while(i<j) {
            ans=max(ans, nums[i++]+nums[j--]);
        }
        return ans;
    }
};