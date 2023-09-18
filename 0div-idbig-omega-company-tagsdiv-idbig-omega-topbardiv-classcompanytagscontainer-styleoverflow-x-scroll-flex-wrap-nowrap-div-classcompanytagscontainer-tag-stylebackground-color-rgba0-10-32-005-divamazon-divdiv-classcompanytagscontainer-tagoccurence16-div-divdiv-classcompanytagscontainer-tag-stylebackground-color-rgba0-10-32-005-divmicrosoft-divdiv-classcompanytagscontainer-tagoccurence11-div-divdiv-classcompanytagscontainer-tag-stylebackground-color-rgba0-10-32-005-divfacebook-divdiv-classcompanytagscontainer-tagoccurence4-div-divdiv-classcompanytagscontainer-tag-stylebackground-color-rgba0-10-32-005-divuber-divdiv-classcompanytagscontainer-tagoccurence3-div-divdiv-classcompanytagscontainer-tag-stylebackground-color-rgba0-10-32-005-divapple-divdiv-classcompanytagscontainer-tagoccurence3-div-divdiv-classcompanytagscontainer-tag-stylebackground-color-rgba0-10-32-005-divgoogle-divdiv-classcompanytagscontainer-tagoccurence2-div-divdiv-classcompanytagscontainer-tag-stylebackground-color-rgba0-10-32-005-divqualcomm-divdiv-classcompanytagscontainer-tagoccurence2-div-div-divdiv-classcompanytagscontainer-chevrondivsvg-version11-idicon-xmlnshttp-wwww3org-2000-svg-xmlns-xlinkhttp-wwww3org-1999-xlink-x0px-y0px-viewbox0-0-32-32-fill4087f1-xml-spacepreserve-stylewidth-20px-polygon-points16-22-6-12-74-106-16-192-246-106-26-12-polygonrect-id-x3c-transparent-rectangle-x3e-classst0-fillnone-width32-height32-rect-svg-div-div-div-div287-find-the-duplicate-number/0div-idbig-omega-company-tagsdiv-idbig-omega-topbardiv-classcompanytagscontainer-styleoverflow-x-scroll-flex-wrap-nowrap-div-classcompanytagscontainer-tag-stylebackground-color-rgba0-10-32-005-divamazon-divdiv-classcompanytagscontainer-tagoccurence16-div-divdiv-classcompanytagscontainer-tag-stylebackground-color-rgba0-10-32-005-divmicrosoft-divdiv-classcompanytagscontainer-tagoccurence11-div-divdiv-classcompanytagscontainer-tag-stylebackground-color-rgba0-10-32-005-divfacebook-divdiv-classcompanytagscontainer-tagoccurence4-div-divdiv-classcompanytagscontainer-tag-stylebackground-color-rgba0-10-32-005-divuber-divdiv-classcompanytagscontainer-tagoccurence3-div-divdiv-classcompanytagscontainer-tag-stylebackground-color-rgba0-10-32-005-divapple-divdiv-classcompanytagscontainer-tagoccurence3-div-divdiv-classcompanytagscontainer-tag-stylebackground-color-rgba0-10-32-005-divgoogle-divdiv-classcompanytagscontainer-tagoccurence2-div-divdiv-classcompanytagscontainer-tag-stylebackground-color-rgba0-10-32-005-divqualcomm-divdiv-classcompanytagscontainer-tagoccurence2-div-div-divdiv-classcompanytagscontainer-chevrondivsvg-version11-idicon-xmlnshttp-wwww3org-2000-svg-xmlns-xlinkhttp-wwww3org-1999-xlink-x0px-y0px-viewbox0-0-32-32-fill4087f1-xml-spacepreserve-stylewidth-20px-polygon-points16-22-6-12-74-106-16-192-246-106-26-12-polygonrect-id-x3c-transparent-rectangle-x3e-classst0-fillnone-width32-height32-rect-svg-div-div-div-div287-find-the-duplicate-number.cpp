class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int n=A.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) {
            if(mp.find(A[i])!=mp.end()) {
                return A[i];
            } else {
                mp[A[i]]++;
            }
        }
        return -1;
    }
};