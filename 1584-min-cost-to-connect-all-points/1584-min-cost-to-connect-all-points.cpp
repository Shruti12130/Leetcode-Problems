class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=1) {
            return 0;
        }
        auto cost = [](int x1, int y1, int x2, int y2) {
            return abs(x1-x2)+abs(y1-y2);
        };
        
        vector<int> dist(n, 0);
        dist[0]=INT_MAX;
        for(int i=1;i<n;i++) {
            dist[i]=cost(points[0][0], points[0][1], points[i][0], points[i][1]);
        }
        
        int ans=0;
        for(int i=1;i<n;i++) {
            auto it=min_element(dist.begin(), dist.end());
            int idx=it-dist.begin();
            ans+=(*it);
            *it=INT_MAX;
            
            for(int i=0;i<n;i++) {
                if(dist[i]!=INT_MAX) {
                    dist[i] = min(dist[i], cost(points[i][0], points[i][1],
                                               points[idx][0], points[idx][1]));
                }
            }
        }
        return ans;
        
    }
};