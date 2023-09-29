class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) {
            return 1;
        }
        bool inc=1, dec=1;
        for(int i=1;i<n;i++) {
            if(nums[i-1] > nums[i]) {
                inc=0;
            }
        }
        for(int i=1;i<n;i++) {
            if(nums[i-1] < nums[i]) {
                dec=0;
            }
        }
        return (inc || dec);
    }
};