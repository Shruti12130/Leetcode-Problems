class Solution {
public:
    void merge(vector<int> &arr, int lo, int mid, int hi) {
        vector<int> temp;
        int left=lo;
        int right=mid+1;
        while(left<=mid && right<=hi) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left++]); 
            } else {
                temp.push_back(arr[right++]);
            }
        }
        
        while(left<=mid) {
            temp.push_back(arr[left++]);
        }
        while(right<=hi) {
            temp.push_back(arr[right++]);
        }
        for(int i=lo;i<=hi;i++) {
            arr[i]=temp[i-lo];
        }
    }
    
    int countReversePairs(vector<int> &arr, int lo, int mid, int hi) {
        int cnt=0;
        int right=mid+1;
        for(int i=lo;i<=mid;i++) {
            while(right<=hi && arr[i] > 1LL*2*arr[right]) {
                right++;
            }
            cnt+=(right-(mid+1));
        }
        return cnt;
    }
    
    int mergeSort(vector<int> &arr, int lo, int hi) {
        int cnt=0;
        if(lo>=hi) {
            return cnt;
        }
        int mid=(lo+hi)/2;
        cnt += mergeSort(arr, lo, mid);
        cnt += mergeSort(arr, mid+1, hi);
        cnt += countReversePairs(arr, lo, mid, hi);
        merge(arr, lo, mid, hi);
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr = nums;
        return mergeSort(arr, 0, n-1);
    }
};