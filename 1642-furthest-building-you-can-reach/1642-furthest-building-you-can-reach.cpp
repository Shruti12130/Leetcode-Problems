class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), sum=bricks, i;
        priority_queue<int> pq;
        
        for(i=0;i<n-1;i++){
            if(heights[i]<heights[i+1]){
                int diff=heights[i]-heights[i+1];
                pq.push(diff);
            }
             
            if(pq.size()>ladders){
                int k = pq.top();  
                pq.pop();
                sum+=k;
            }
            
            if(sum<0)
                return i;
        }
        return i;
    }
};