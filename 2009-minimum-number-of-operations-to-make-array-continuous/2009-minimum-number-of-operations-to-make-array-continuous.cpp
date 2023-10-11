class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        
        int ans=n+1;
        set<int> st(nums.begin(), nums.end());
        vector<int> temp;
        for(int it: st) {
            temp.push_back(it);
        }
        for(int i=0;i<temp.size();i++) {
            int lo = temp[i];
            int hi = lo + (n-1);
            int idx = upper_bound(temp.begin(), temp.end(), hi) - temp.begin();
            int len = (idx-i);
            ans = min(ans, n-len);
        }
        return ans;
    }
};