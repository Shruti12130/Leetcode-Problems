class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, 
                                          vector<int>& r) {
        int n=nums.size(), m=l.size();
        vector<bool> ans(m);
        for(int i=0;i<m;i++) {
            int x=l[i], y=r[i];
            if(x==y || x+1==y) {
                ans[i]=true;
                continue;
            }
            vector<int> temp;
            temp.insert(temp.end(), nums.begin()+x, nums.begin()+y+1);
            sort(temp.begin(), temp.end());
            bool flag=true;
            int diff=temp[1]-temp[0];
            for(int j=2;j<temp.size();j++) {
                if(temp[j]-temp[j-1]!=diff) {
                    flag=false;
                    break;
                }
            }
            ans[i]=flag;
        }
        return ans;
    }
};