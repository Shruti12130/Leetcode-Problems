class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n), ans(n);
        pre[0]=nums[0];
        
        for(int i=1;i<n;i++) {
            pre[i]=pre[i-1]+nums[i];
        }
        ans[0]=pre[n-1]-n*nums[0];
        for(int i=1;i<n;i++) {
            ans[i]=(i*nums[i]-pre[i-1]) + pre[n-1]-pre[i]-(n-1-i)*nums[i];
        }
        
        return ans;
    }
};