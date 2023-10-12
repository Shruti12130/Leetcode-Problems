/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int i=0, j=n-1;
        int peak;
        
        while(i<j) {
            int mid=(i+j)/2;
            int midElement=mountainArr.get(mid);
            if(midElement < mountainArr.get(mid+1)) {
                i=mid+1;
            } else {
                j=mid;
            }
        }
        peak = i;
        
        i=0, j=peak;
        while(i<=j) {
            int mid=(i+j)/2;
            int midElement=mountainArr.get(mid);
            if(midElement==target) {
                return mid;
            } else if(midElement > target) {
                j=mid-1;
            } else {
                i=mid+1;
            }
        }
        
        i=peak, j=n-1;
        while(i<=j) {
            int mid=(i+j)/2;
            int midElement=mountainArr.get(mid);
            if(midElement==target) {
                return mid;
            } else if(midElement < target) {
                j=mid-1;
            } else {
                i=mid+1;
            }
        }
        return -1;
    }
};