class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        
        for(int i=1;i<numRows;i++) {
            vector<int> temp(i+1);
            temp[0]=1, temp[i]=1;
            int prevRow=i-1;
            for(int j=1;j<i;j++) {
                temp[j]=ans[prevRow][j-1]+ans[prevRow][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};