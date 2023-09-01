class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals(n+1, vector<int>(2));
        
        for(int i=0;i<=n;i++) {
            intervals[i][0]=max(0, i-ranges[i]);
            intervals[i][1]=i+ranges[i];
        }
        
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0]<b[0];
        });
        
        
        int i=1, last=intervals[0][1], ans=1;
        while(i<=n) {
            if(last>=n) {
                return ans;
            }
            int k=last; 
            while(i<=n && intervals[i][0]<=last) {
                k=max(k, intervals[i++][1]);
            }
            if(k==last) {
                return -1;
            }
            last=k;
            ans++;
        }
        return ans;
    }
};