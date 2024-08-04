class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> sum;
        int mod=1e9+7;
        
        for(int i=0;i<nums.size();i++) {
            long long tempSum=0;
            for(int j=i;j<nums.size();j++) {
                tempSum+=nums[j];
                sum.push_back(tempSum);
            }
        }
        
        sort(sum.begin(), sum.end());
        long long ans=0;
        for(int i=left-1;i<right;i++) {
            (ans+=sum[i])%=mod;
        }
        return ans;
    }
};