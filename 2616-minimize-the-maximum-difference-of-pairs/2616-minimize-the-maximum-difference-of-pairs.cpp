class Solution {
public:
    int numOfPairs(int dist, vector<int> &nums) {
        int n=nums.size(), cnt=0;
        
        for(int i=1;i<n;i++) {
            if(nums[i]-nums[i-1]<=dist) {
                i++, cnt++;
            }
        }
        return cnt;
        
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int i=0, j=nums[n-1], ans;
        while(i<=j) {
            int mid=(i+j)/2;
            int cnt=numOfPairs(mid, nums);
            
            if(cnt>=p) {
                ans=mid;
                j=mid-1;
            } else {
                i=mid+1;
            }
        }
        
        return ans;
    }
};