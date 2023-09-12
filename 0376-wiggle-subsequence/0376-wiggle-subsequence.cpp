class Solution {
public:
    int dp[1001];
        
    int solve(int i, int diff, vector<int> &nums) {
        int n=nums.size();
        if(i==n-1) {
            return 1;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans=0;
        if(i+1<n) {
            int currDiff=nums[i+1]-nums[i];
            if(diff*currDiff<0) {
                return dp[i]=1+solve(i+1, currDiff, nums);
            } else {
                return dp[i]=solve(i+1, diff, nums);
            } 
        } 
        return dp[i]=0;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) {
            if(n==2 && nums[0]==nums[1]) return 1;
            return n;
        }
        memset(dp, -1, sizeof(dp));
        int i=1;
        while(i<n && nums[i]==nums[i-1])  i++;
        return 1+solve(i, nums[i]-nums[i-1], nums);
    }
};