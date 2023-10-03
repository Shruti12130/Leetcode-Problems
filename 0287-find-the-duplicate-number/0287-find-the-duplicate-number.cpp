class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int n=A.size();
        vector<int> v(n+1, 0);
        for(int i=0;i<n;i++) {
            if(v[A[i]]==1) {
                return A[i];
            } else {
                v[A[i]]++;
            }
        }
        return -1;
    }
};