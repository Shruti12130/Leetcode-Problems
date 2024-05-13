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
    
    void mergeSort(vector<int> &arr, int lo, int hi) {
        if(lo>=hi) {
            return;
        }
        int mid=(lo+hi)/2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid+1, hi);
        merge(arr, lo, mid, hi);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr = nums;
        mergeSort(arr, 0, n-1);
        return arr;
    }
};