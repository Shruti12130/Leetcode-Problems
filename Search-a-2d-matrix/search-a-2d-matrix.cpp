class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        
        int i=0, j=n*m-1;
        while(i<=j) {
            int mid=(i+j)/2;
            int val=matrix[mid/m][mid%m];
            
            if(val==target) {
                return true;
            } else if(val>target) {
                j=mid-1;
            } else {
                i=mid+1;
            }
        }
        return false;
    }
};
