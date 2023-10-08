class Solution {
public:
    int dp[501][501], n, m;
    
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i>=n || j>=m) {
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take = nums1[i]*nums2[j] + solve(i+1, j+1, nums1, nums2);
        int dontTake = max(solve(i+1, j, nums1, nums2), solve(i, j+1, nums1, nums2));
        
        return dp[i][j] = max(take, dontTake);
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size(), m=nums2.size();
        int max1 = *max_element(nums1.begin(), nums1.end());
        int min1 = *min_element(nums1.begin(), nums1.end());
        int max2 = *max_element(nums2.begin(), nums2.end());
        int min2 = *min_element(nums2.begin(), nums2.end());
        
        if(max1 < 0 && min2 > 0) {
            return max1*min2;
        }
        
        if(max2 < 0 && min1 > 0) {
            return max2*min1;
        }
        
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums1, nums2);
    }
};