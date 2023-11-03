class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int sz=target.size();
        vector<string> ans;
        int count=1;
        
        for(int i=0;i<sz;i++) {
            int k=target[i];
            if(count==k) {
                ans.push_back("Push");
            } else if(count<k) {
                while(count<=k-1) {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    count++;
                }
                ans.push_back("Push");
            }
            count++;
        }
        
        return ans;
    }
};