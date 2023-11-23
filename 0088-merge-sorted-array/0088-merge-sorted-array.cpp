class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) {
            return;
        }
        int j=0;
        for(int i=m;i<m+n;i++) {
            nums1[i]=INT_MIN;
        }
        for(int i=0;i<m+n && j<n;i++) {
            if(nums1[i]>nums2[j]) {
                nums1.pop_back();
                nums1.insert(nums1.begin()+i, nums2[j]);
                i--;
                j++;
            } else if(nums1[i]==INT_MIN) {
                nums1[i]=nums2[j++];
            }
        }
    }
};