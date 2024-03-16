class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        if(nums.size()==1) {
            return nums[0];
        }
        while(i<j) {
            if(nums[i]<nums[j]) {
                return nums[i];
            }
            int mid=(i+j)/2;
            if(nums[i]<=nums[mid]) {
                i=mid+1;
            } else {
                j=mid;
            }
        }
        return nums[i];
    }
};