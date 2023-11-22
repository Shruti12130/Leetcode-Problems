class Solution {
public:
    int ans=0;
    void solve(int ind, vector<int> &nums) {
        int n=nums.size();
        if(ind==n) {
            ans++;
            return;
        }
        
        for(int i=ind;i<n;i++) {
            swap(nums[ind], nums[i]);
            if(nums[ind]%(ind)==0 || (ind)%nums[ind]==0) {
                solve(ind+1, nums);
            }
            swap(nums[ind], nums[i]);
        }
    }
    
    int countArrangement(int n) {
        vector<int> nums(n+1);
        for(int i=1;i<=n;i++) {
            nums[i]=i;
        }
        solve(1, nums);
        return ans;
    }
};