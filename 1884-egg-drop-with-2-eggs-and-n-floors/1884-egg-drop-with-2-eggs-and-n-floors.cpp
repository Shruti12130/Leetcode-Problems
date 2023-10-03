class Solution {
public:
    int dp[101][10001];
    int solve(int egg, int floor) {
        if(floor<=1) {
            return floor;
        }
        if(egg==1) {   //Worst case scenaio if we have only 1 egg
            return floor;
        }
        if(dp[egg][floor]!=-1) {
            return dp[egg][floor];
        }
        int i=1, j=floor, temp=0, ans=INT_MAX;
        while(i<=j) {
            int mid=(i+j)/2;
            
            //If egg broke
            int lo = solve(egg-1, mid-1);
            int hi = solve(egg, floor-mid);
            int temp=1+max(lo, hi);
            
            if(lo < hi) {
                i=mid+1;
            } else {
                j=mid-1;
            }
            ans=min(ans, temp);
        }
        return dp[egg][floor] = ans;
    }
    
    int twoEggDrop(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(2, n);
    }
};