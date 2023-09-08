class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int smallestPositive=INT_MAX;
        
        for(int i=0;i<n;i++) {
            if(nums[i]>0 && nums[i]<smallestPositive) {
                smallestPositive = nums[i];
            }
        }
        if(smallestPositive!=1) {
            return 1;
        }
        vector<int> temp(1e5+1, 0);
        for(int i=0;i<n;i++) {
            if(nums[i]>0 && nums[i]<1e5+1) {
                temp[nums[i]]++;
            }
        }
        for(int i=1;i<temp.size();i++) {
            if(temp[i]==0) {
                return i;
            }
        }
        return n+1;
    }
};