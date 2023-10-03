class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int cnt=0, prod;
        if(nums[0]==0)  cnt++;
        prod=(nums[0]!=0) ? nums[0] : 1;
        vector<int> pre(n), suf(n);
        pre[0]=1;
        for(int i=1;i<n;i++) {
            if(nums[i]==0)  cnt++;
            if(nums[i]!=0)  prod*=nums[i];
            pre[i]=pre[i-1]*nums[i-1];
        }
        suf[n-1]=1;
        for(int i=n-2;i>=0;i--) {
            suf[i]=suf[i+1]*nums[i+1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ans[i]=pre[i]*suf[i];
        }
        return ans;
    }
};