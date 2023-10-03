class Solution {
public:
    
    bool check(int mid, vector<int>& nums, int k) {
        int c=1, n=nums.size(), sum=0;
        for(int i=0;i<n;i++) {
            if(sum+nums[i]<=mid) {
                sum+=nums[i];
            } else {
                c++;
                sum=nums[i];
            }
        }
        
        return c<=k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int maxi = *max_element(nums.begin(), nums.end());
        
        int i=maxi, j=sum, ans=0;
        while(i<=j) {
            int mid=(i+j)/2;
            if(check(mid, nums, k)) {
                j=mid-1;
                ans=mid;
            } else {
                i=mid+1;
            }
        }
        return ans;
    }
};