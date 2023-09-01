class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        if(n==0) {
            return ans;
        }
        int prev=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            //temp=no of fragments we can divide curr no into
            int temp=nums[i]/prev;
            if(nums[i]%prev!=0) {
                temp++;
                prev=nums[i]/temp;
            }
            //(temp-1) is the minimum time of splits
            ans+=(temp-1);
        }
        return ans;
    }
};