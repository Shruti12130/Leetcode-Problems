class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int k=n/4, c=1, ans=arr[0];
        for(int i=1;i<n;i++) {
            if(arr[i]==arr[i-1]) {
                c++;
                if(c>k) {
                    return arr[i];
                }
            } else {
                c=1;
            }
        }
        return ans;
    }
};