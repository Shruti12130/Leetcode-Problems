class Solution {
public:
    vector<int> ans;
    
    void merge(vector<pair<int, int>> &v, int lo, int mid, int hi) {
        vector<pair<int, int>> temp;
        int left=lo;
        int right=mid+1;
        
        while(left<=mid && right<=hi) {
            if(v[left].first > v[right].first) {
                ans[v[left].second] += (hi-right+1);
                temp.push_back(v[left]);
                left++;
            } else {
                temp.push_back(v[right]);
                right++;
            }
        }
        
        while(left<=mid) {
            temp.push_back(v[left++]);
        }
        
        while(right<=hi) {
            temp.push_back(v[right++]);
        }
        for(int i=lo;i<=hi;i++) {
            v[i]=temp[i-lo];
        }
    }
    
    void mergeSort(vector<pair<int, int>> &v, int lo, int hi) {
        if(lo>=hi) {
            return;
        }
        int mid=(lo + hi)/2;
        mergeSort(v, lo, mid);
        mergeSort(v, mid+1, hi);
        merge(v, lo, mid, hi);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        ans.resize(n, 0);
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++) {
            v[i] = {nums[i], i};
        }
        mergeSort(v, 0, n-1);
        return ans;
    }
};