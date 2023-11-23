class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1) {
            return intervals;
        }
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int start=intervals[0][0], end=intervals[0][1];
        
        for(int i=1;i<n;i++) {
            while(i<n && intervals[i][0]<=end) {
                end=max(end, intervals[i][1]);
                i++;
            }
            i--;
            ans.push_back({start, end});
            if(i+1<n) {
                start=intervals[i+1][0], end=intervals[i+1][1];
            }
        }
        return ans;
    }
};