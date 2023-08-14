class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        
        for(auto it: nums) {
            pq.push(it);
        }
        int i=0;
        while(!pq.empty()) {
            int ele = pq.top();
            pq.pop();
            if(i==k-1) {
                return ele;
            }
            i++;
        }
        return -1;
    }
};