class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        vector<int> mxL(n), mxR(n);
        mxL[0]=height[0];
        mxR[n-1]=height[n-1];
        int ans=0;
        
        for(int i=1;i<n;i++) {
            mxL[i]=max(mxL[i-1], height[i]);
        }
        for(int i=n-2;i>=0;i--) {
            mxR[i]=max(mxR[i+1], height[i]);
        }
        for(int i=0;i<n;i++) {
            int temp = min(mxL[i], mxR[i]);
            if(temp>height[i]) {
                ans += (temp-height[i]);
            }
        }
        return ans;
    }
};