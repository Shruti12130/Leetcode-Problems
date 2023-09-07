class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        
        //Find the first number that is not greater than its next adjacent number
        while(i>=0 && nums[i] >= nums[i+1]) {
            i--;
        }
        //if all the numbers are in decreasing order then its the largest permutation,
        //reverse the array to get the smallest permutation for this array 
        if(i<0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        //Else find the first number that is greater than the above noted digit and 
        //swap both numbers's position 
        int j=n-1;
        while(nums[i] >= nums[j]) {
            j--;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
    }
};