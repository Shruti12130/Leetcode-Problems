class Solution {
public:
    typedef pair<int, pair<int, int>> pi;
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // queue<array<int, 3>> q;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        d[0][0]=0;
        int ans=0;
        
        while(!pq.empty()) {
            auto k = pq.top();
            int dis=k.first, i=k.second.first, j=k.second.second;
            pq.pop();
            if(i==n-1 && j==m-1) {
                return dis;
            }
            
            for(auto it: dirs) {
                int x=i+it[0];
                int y=j+it[1];
                
                if(x>=0 && y>=0 && x<n && y<m) {
                    int tempDis = max(dis, abs(heights[x][y]-heights[i][j]));
                    if(tempDis < d[x][y]) {
                        d[x][y]=tempDis;
                        pq.push({tempDis, {x, y}});
                    }
                }
            }
        }
        return 0;
    }
};