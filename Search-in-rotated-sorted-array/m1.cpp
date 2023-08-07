class Solution {
public:
    
    int binarySearch(int i, int j, int target, vector<int> &arr) {
        while(i<=j) {
            int mid=(i+j)/2;
            if(arr[mid]==target) {
                return mid;
            } else if(arr[mid] > target) {
                j=mid-1;
            } else {
                i=mid+1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0, j=n-1;

        //Finding the pivot point
        while(i<=j) {
            int mid=(i+j)/2;
            if(arr[mid] > arr[n-1]) {
                i=mid+1;
            } else {
                j=mid-1;
            }
        }
        
        int ans = binarySearch(0, i-1, target, arr);
        if(ans != -1) {
            return ans;
        }
        return binarySearch(i, n-1, target, arr);
    }
};
