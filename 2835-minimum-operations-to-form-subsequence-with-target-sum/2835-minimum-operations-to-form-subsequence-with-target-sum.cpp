class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(), nums.end(), 0LL);
        if(sum < target) {
            return -1;
        }
        
        long long ans=0;
        sort(nums.begin(), nums.end());
        
        while(target>0) {
            long long x=nums.back();
            nums.pop_back();
            
            if(sum-x>=target) {
                sum-=x;
            } else if(target>=x) {
                target-=x;
                sum-=x;
            } else {
                nums.push_back(x/2);
                nums.push_back(x/2);
                ans++;
            }
        }
        
        return (int)ans;
    }
};