class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n=A.size();
        int i=n-2, j=n-1;
        while(i>=0) {
            if(A[i]<A[i+1]) {
                break;
            } 
            i--;
        }
        if(i<0) {
            reverse(A.begin(), A.end());
        } else {
            int k=A[i], j=n-1;
            while(k>=A[j]) {
                j--;
            }
            swap(A[i], A[j]);
            reverse(A.begin()+i+1, A.end());
        }

    }
};