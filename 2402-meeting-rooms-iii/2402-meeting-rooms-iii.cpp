class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> p1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
        //{end_time, room_no} 
        greater<pair<long long, int>>> p2;
        
        sort(meetings.begin(), meetings.end());
        vector<int> rooms(n, 0);
        
        for(int i=0;i<n;i++) {
            p1.push(i);
        }
        
        for(auto it: meetings) {
            int start=it[0], end=it[1];
            while(!p2.empty() && p2.top().first<=start) {
                auto k=p2.top();
                p2.pop();
                
                p1.push(k.second);
            }
            if(!p1.empty()) {
                int r=p1.top();
                p1.pop();
                
                rooms[r]++;
                p2.push({end, r});
            } else {
                auto k=p2.top();
                p2.pop();
                
                rooms[k.second]++;
                
                long long newEnd=k.first+(end-start);
                p2.push({newEnd, k.second});
            }
        }
        int maxi=0;
        for(int i=1;i<n;i++) {
            if(rooms[i]>rooms[maxi]) {
                maxi=i;
            }
        }
        return maxi;
    }
};