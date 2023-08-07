class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0, j=n-1;
        
        while(i<=j) {
            int mid=(i+j)/2;
            
            //either the left half or the right half is fully sorted
            
            if(nums[mid]==target) 
                return mid;
            else if(nums[i] <= nums[mid])  {  //left subarray sorted
                if(nums[i] <= target && target<=nums[mid]) 
                    j=mid-1;
                else
                    i=mid+1;
            } else { //if left half is not sorted then the right one is surely sorted
                if(nums[mid]<=target && target<=nums[j]) 
                    i=mid+1;
                else
                    j=mid-1;
            }
            
        }
        return -1;
    }
};
