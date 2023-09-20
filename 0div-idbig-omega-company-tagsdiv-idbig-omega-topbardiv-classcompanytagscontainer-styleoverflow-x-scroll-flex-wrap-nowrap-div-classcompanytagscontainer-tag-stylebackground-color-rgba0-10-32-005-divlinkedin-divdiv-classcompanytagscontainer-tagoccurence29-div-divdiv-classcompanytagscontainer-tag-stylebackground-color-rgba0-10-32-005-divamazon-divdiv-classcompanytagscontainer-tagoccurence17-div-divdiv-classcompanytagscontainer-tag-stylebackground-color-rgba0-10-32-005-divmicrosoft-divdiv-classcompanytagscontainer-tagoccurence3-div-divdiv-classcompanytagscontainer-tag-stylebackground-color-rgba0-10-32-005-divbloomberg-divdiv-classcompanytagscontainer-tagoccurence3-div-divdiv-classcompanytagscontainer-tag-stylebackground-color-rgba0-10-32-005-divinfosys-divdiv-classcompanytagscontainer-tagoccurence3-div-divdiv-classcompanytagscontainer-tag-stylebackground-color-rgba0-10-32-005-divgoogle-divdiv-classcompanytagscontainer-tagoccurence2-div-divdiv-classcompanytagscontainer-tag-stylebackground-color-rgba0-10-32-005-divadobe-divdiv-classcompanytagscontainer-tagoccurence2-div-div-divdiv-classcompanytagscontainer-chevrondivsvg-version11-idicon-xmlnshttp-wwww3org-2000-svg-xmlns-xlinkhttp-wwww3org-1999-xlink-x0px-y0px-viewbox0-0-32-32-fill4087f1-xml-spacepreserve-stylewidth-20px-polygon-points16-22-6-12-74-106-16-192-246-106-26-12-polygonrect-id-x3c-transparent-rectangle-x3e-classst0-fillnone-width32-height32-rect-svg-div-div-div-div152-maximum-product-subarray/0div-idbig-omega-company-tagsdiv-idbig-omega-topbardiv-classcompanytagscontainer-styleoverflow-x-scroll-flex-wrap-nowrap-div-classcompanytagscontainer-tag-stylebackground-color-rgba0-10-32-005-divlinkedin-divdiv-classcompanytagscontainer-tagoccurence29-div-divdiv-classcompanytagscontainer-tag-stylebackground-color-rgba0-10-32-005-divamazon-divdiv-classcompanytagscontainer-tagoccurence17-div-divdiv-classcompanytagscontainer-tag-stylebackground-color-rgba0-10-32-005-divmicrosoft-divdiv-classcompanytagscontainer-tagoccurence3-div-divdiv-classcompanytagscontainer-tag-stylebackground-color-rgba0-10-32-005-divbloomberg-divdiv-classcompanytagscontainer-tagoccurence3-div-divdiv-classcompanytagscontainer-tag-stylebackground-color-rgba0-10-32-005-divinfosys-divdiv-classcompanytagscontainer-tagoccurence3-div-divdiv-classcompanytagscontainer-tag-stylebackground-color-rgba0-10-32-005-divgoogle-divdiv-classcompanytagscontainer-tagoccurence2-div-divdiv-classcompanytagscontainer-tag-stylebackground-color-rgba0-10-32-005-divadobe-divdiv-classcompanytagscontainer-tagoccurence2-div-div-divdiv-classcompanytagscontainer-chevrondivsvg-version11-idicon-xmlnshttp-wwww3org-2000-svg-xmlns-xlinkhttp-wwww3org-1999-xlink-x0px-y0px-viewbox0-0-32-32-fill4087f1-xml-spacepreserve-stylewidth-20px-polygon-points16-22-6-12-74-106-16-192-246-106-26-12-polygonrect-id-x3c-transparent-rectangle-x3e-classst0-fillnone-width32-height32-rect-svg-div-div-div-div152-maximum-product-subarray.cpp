class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int l=1, r=1, mx=nums[0];
        for(int j=0;j<n;j++) {
            l*=nums[j];
            r*=nums[n-1-j];
            mx=max(mx, max(l, r));
            if(l==0) {
                l=1;
            }
            if(r==0) {
                r=1;
            }
        }
        return mx;
    }
};