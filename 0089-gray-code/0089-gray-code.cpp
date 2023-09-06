class Solution {
public:
    vector<int> grayCode(int n) {
        //Every time we just twiced the values in the prev result and
        //new values are just made by setting (n-1)th bit to 1, 
        //iterating from right in the prev result ;
        
        vector<int> ans;
        ans.push_back(0);
        
        for(int i=1;i<=n;i++) {
            int prevLen = ans.size();
            //mask containes (n-1)th bit as 1
            int mask = 1 << (i-1);  
            for(int j=prevLen-1;j>=0;j--) { 
                ans.push_back(mask+ans[j]);
            }cout<<endl;
        }
        return ans;
    }
};