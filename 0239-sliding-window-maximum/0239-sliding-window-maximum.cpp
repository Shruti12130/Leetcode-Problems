class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        multiset<int> ms;
        int mx=-1e9;
        for(int j=0;j<n;j++) {
            if(j<k) {
                ms.insert(nums[j]);
                mx=max(mx, nums[j]);
                if(j==k-1) {
                    ans.push_back(mx);
                }
                continue;
            }
            ms.insert(nums[j]);
            ms.erase(ms.find(nums[j-k]));
            mx=*(ms.rbegin());
            ans.push_back(mx);
        }
        return ans;
    }
};