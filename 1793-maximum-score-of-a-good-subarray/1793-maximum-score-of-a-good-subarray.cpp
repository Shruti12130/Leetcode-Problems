class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=nums[k], mini=nums[k], len=1;
        int i=k, j=k;
        while(i>0 || j<n-1) {
            if(i==0) {
                j++;
            } else if(j==n-1) {
                i--;
            } else {
                if(nums[i-1] < nums[j+1]) {
                    j++;
                } else {
                    i--;
                }
            }
            mini=min(mini, min(nums[i], nums[j]));
            len++;
            ans=max(ans, mini*len);
        }
        return ans;
    }
};