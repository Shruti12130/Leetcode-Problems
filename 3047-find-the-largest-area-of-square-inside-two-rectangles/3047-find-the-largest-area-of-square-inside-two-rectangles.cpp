class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        long long ans=0LL;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i!=j) {
                    int x1=max(bottomLeft[i][0], bottomLeft[j][0]);
                    int y1=max(bottomLeft[i][1], bottomLeft[j][1]);
                    int x2=min(topRight[i][0], topRight[j][0]);
                    int y2=min(topRight[i][1], topRight[j][1]);
                    
                    if(x1<x2 && y1<y2) {
                        long long side=min(x2-x1, y2-y1);
                        ans=max(ans, 1LL*side*side);
                    }
                }
            }
        }
        return ans;
    }
};