class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0, count=0;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) {
            nums[i]==1 ? count++ : count--;
            if(count==0) {
                ans=max(ans, i+1);
            }
            if(mp.count(count)) {
                ans=max(ans, i-mp[count]);
            } else {
                mp[count]=i;   
            }
        }
        return ans;
    }
};