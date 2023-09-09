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
            if(nums[ind]%(ind+1)==0 || (ind+1)%nums[ind]==0) {
                solve(ind+1, nums);
            }
            swap(nums[ind], nums[i]);
        }
    }
    
    int countArrangement(int n) {
        vector<int> nums(n);
        for(int i=0;i<n;i++) {
            nums[i]=i+1;
        }
        solve(0, nums);
        return ans;
    }
};