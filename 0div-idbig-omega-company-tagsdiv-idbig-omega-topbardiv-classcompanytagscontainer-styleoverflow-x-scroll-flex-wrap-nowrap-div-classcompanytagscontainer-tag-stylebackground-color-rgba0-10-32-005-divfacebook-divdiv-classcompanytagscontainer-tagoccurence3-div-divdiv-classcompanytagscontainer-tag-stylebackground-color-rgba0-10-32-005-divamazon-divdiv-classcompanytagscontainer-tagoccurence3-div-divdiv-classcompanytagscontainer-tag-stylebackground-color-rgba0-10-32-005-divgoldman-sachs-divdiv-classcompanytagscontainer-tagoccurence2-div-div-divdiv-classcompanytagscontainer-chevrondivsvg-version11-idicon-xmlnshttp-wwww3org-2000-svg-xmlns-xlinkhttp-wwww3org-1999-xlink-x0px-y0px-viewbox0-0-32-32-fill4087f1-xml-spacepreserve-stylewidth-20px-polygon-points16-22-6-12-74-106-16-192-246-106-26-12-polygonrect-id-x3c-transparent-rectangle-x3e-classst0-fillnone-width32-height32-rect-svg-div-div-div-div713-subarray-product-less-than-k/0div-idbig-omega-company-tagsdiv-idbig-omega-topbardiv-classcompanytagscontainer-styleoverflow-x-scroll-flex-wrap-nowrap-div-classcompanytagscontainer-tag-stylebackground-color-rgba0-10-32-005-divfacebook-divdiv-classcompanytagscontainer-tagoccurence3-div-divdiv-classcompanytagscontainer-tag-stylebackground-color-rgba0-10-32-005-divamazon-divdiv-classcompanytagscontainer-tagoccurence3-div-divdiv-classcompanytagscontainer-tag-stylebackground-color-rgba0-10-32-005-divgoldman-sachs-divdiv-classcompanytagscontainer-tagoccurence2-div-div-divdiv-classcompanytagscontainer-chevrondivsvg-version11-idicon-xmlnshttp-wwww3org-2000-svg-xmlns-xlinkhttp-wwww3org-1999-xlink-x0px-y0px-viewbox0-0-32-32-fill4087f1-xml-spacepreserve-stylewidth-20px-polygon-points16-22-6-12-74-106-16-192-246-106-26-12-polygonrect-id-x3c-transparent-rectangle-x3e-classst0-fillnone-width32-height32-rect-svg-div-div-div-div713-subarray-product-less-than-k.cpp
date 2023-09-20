class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1) {
            return 0;
        }
        long long i=0, ans=0, prod=1;
        for(int j=0;j<n;j++) {
            prod*=nums[j];//cout<<prod<<' ';
            while(prod>=k) {
                prod/=nums[i++];
            }
            ans+=(j-i+1);
        }
        return (int)ans;
    }
};