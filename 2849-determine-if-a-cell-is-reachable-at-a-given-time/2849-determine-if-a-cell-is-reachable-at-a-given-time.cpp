class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int c=0;
        if(sx==fx && sy==fy && t==1) {
            return false;
        }
        int ax=abs(sx-fx), ay=abs(sy-fy);
        c=min(ax, ay)+abs(ax-ay);
        return (c<=t);
    }
};