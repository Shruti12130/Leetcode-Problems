class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n+1);
        
        for(int i=0;i<=n;i++) {
            int k=max(0, i-ranges[i]);
            arr[k]=max(arr[k], i+ranges[i]);
        }
        
        int i=0, last=0, maxDist=0, ans=0;
        while(i<arr.size() && last<n) {
            ans++;
            while(i<arr.size() && i<=last) {
                maxDist=max(maxDist, arr[i++]);
            }
            if(last==maxDist) {
                return -1;
            }
            last=maxDist;
        }
        return ans;
    }
};