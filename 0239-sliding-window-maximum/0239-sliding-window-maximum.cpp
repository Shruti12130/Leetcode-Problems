class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        
        for(int j=0;j<n;j++) {
            //To remove the left side element out of the dq which is no more a part of window
            if(!dq.empty() && dq.front() == j-k) {
                dq.pop_front();
            }
            //To maintain the sorted order inside dq
            //Going from left to right(front to back), elements are in sorted order
            while(!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            
            dq.push_back(j);
            
            //Pushing the element into ans vector
            if(j>=k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};