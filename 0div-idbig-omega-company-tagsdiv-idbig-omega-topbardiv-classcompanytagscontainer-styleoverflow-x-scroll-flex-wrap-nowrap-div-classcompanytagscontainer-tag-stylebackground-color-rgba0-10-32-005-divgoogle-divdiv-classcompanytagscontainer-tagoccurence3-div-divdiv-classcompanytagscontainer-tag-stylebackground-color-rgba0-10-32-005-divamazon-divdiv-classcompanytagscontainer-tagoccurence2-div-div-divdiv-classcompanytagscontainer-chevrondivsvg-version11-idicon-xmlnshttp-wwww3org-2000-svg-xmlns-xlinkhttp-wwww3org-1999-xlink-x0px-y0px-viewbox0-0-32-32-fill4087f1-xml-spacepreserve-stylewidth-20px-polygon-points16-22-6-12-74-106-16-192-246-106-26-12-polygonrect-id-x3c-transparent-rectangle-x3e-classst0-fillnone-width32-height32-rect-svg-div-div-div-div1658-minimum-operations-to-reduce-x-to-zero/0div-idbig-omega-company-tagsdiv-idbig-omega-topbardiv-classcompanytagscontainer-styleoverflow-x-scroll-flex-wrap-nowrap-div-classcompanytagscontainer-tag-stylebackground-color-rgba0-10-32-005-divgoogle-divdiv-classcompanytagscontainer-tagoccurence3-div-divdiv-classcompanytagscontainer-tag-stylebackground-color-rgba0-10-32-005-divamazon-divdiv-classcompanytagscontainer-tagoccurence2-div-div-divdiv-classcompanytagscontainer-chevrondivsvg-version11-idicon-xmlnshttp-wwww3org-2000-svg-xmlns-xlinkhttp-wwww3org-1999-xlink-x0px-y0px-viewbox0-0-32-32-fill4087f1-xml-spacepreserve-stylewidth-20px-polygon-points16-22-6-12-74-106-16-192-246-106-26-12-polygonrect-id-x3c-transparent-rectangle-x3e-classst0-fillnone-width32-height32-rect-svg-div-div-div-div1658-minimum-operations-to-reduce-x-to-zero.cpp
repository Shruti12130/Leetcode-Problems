class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
    
        int s=sum-x;
        if(s==0)  return n;
        if(s<0)  return -1;
        
        int i=0, j=0, c=0, k=0;
        while(j<n){
            c+=nums[j];
            while(c>=s){
                if(c==s) {
                    k=max(k, j-i+1);
                }
                c-=nums[i++];
            }
            j++;
        }
        if(k==0)  return -1;
        return n-k;
    }
};